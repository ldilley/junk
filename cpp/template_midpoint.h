#ifndef TEMPLATE_MIDPOINT_H
#define TEMPLATE_MIDPOINT_H

template <typename T>
class Interval
{
  public:
    Interval();
    Interval(T start, T end);
    T midpoint();
  private:
    T a;
    T b;
};

#endif // TEMPLATE_MIDPOINT_H
