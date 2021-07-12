#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
  const int size = 256256;
  double sinTable[size];
  
#pragma omp parallel for schedule(dynamic)
  for(int n=0; n<size; ++n)
  {
    auto d=0.0;
    for(auto i = 0 ; i < 10000;++i)
      d+=  std::sin(2 * M_PI * n / size);
    sinTable[n] = d;
  }
  
  double sum=0.0;
  for(auto v: sinTable)
    sum += v;
  std::cout<<" Sum = "<<sum<<std::endl;
  return 0;
}
