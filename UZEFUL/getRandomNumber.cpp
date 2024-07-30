#include <cstdlib>
// Генерируем случайное число между min и max (включительно).
// Предполагается, что srand() уже был вызван
static int getRandomNumber(int min, int max) {
// используем static, так как это значение нужно вычислить единожды
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
// Равномерно распределяем вычисление значения из нашего диапазона
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
