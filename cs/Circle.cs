using System;

class Circle
{
  public static void Main()
  {
    // vars
    int radius = 4;
    const double PI = 3.14159;
    double circum, area;

    // calculations
    area = PI * radius * radius;
    circum = 2 * PI * radius;

    // print results
    Console.WriteLine("Radius = {0}, PI = {1}", radius, PI);
    Console.WriteLine("The area is {0}.", area);
    Console.WriteLine("The circumference is {0}.", circum);
  }
}
