#include «math.h»


double GetAreaOfCircle(const double radius)
{
	return std::math::pi * radius * radius;
};

int main() {
  const double r = 1.23;
  std::cout << "Area of Circle with " << r << " is: " << GetAreaOfCircle(r) << std::endl;
  return 0;
}
