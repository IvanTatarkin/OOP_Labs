#include "solver.h"
#include <gtest/gtest.h>
#include <sstream>

// Тест для общей площади всех фигур в массиве
TEST(FigureTest, ArrayTotalArea) {
    Array array(10);  
    
    // Создание объектов фигур
    Trapezoid* trapezoid = new Trapezoid();
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();

    // Координаты для трапеции, квадрата и прямоугольника
    std::istringstream is1("0 0 4 0 3 2 0 2");  // Трапеция
    std::istringstream is2("1 1 3 1 3 3 1 3");  // Квадрат
    std::istringstream is3("0 0 4 0 4 3 0 3");  // Прямоугольник

    // Ввод данных в объекты
    is1 >> *trapezoid;
    is2 >> *square;
    is3 >> *rectangle;

    // Добавляем фигуры в массив
    array.addFigure(trapezoid);
    array.addFigure(square);
    array.addFigure(rectangle);

    // Вычисляем общую площадь
    double totalArea = array.totalArea();
    std::cout << "Trapezoid area: " << trapezoid->getArea() << std::endl;
    std::cout << "Square area: " << square->getArea() << std::endl;
    std::cout << "Rectangle area: " << rectangle->getArea() << std::endl;

    // Ожидаемая площадь:
    // Трапеция: (0, 0), (4, 0), (3, 2), (0, 2) -> Площадь = 7
    // Квадрат: Площадь = 4
    // Прямоугольник: Площадь = 12
    ASSERT_NEAR(totalArea, 7 + 4 + 12, 0.5);  // Ожидаемая площадь
}

// Тест для общей площади с удалением элемента
TEST(FigureTest, ArrayTotalAreaWithDeleteElement) {
    Array array(10);  
    
    // Создание объектов фигур
    Trapezoid* trapezoid = new Trapezoid();
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();

    // Координаты для трапеции, квадрата и прямоугольника
    std::istringstream is1("0 0 4 0 3 2 0 2");  // Трапеция
    std::istringstream is2("1 1 3 1 3 3 1 3");  // Квадрат
    std::istringstream is3("0 0 4 0 4 3 0 3");  // Прямоугольник

    // Ввод данных в объекты
    is1 >> *trapezoid;
    is2 >> *square;
    is3 >> *rectangle;

    // Добавляем фигуры в массив
    array.addFigure(trapezoid);
    array.addFigure(square);
    array.addFigure(rectangle);

    // Удаляем квадрат
    array.removeFigure(1);

    // Вычисляем общую площадь после удаления квадрата
    double totalArea = array.totalArea();

    // Площадь трапеции = 7, Прямоугольника = 12
    ASSERT_NEAR(totalArea, 7 + 12, 0.5);  // Ожидаемая площадь после удаления
}

// Тест для вывода трапеции в поток
TEST(FigureTest, TrapezoidOutputStream) {
    Trapezoid* trapezoid = new Trapezoid();
    
    // Инициализируем координаты трапеции
    std::istringstream is("0 0 4 0 3 2 0 2");  // Координаты трапеции
    is >> *trapezoid;
    
    std::ostringstream os;
    os << *trapezoid;
    
    std::string expectedOutput = "Trapezoid: ((0, 0), (4, 0), (3, 2), (0, 2))";
    ASSERT_EQ(os.str(), expectedOutput);
}


// Тест для ввода квадрата
TEST(FigureTest, SquareInputStream) {
    Square* square = new Square();
    
    std::istringstream is("1 1 3 1 3 3 1 3");  // Координаты квадрата
    is >> *square;
    
    double area = square->getArea();
    
    ASSERT_NEAR(area, 4, 0.5);  // Площадь квадрата
}

// Тест для оператора double для квадрата
TEST(FigureTest, SquareOperatorDouble) {
    Square* square = new Square();
    
    std::istringstream is("1 1 3 1 3 3 1 3");  // Координаты квадрата
    is >> *square;
    
    double area = static_cast<double>(*square);  // Преобразование в double
    
    ASSERT_NEAR(area, 4, 0.5);  // Площадь квадрата
}

// Тест для корректности расчета центра фигуры (например, для квадрата)
TEST(FigureTest, SquareCenter) {
    Square* square = new Square();
    
    std::istringstream is("1 1 3 1 3 3 1 3");  // Координаты квадрата
    is >> *square;
    
    square->calculateFigureCenter();
    auto center = square->getFigureCenter();
    
    ASSERT_NEAR(center.first, 2, 0.5);  // Ожидаемый центр по X
    ASSERT_NEAR(center.second, 2, 0.5); // Ожидаемый центр по Y
}

// Тест для трапеции: проверка площади и центра
TEST(FigureTest, TrapezoidCenterAndArea) {
    Trapezoid* trapezoid = new Trapezoid();
    
    std::istringstream is("0 0 4 0 3 2 0 2");  // Координаты трапеции
    is >> *trapezoid;
    
    trapezoid->calculateFigureCenter();
    auto center = trapezoid->getFigureCenter();
    
    double area = trapezoid->getArea();
    
    // Проверяем площадь и центр
    ASSERT_NEAR(area, 7, 0.5);  // Площадь трапеции
    ASSERT_NEAR(center.first, 2, 0.5);  // Ожидаемый центр по X
    ASSERT_NEAR(center.second, 1, 0.5); // Ожидаемый центр по Y
}

