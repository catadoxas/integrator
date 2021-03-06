/*
 * Creating the triangulation plot 1.7.23 from NCSE Script
 */

# include <iostream>
# include <Eigen/Dense>
# include <mgl2/mgl.h>

void sample(mglGraph* gr)
{
  // data points
  Eigen::VectorXd x(10), y(10);
  x << 1.0,0.60,0.12,0.81,0.63,0.09,0.27,0.54,0.95,0.96;
  y << 0.15,0.97,0.95,0.48,0.80,0.14,0.42,0.91,0.79,0.95;

  // specify triangles through indices of their vertices
  // NOTE: MathGL's mglData constructor needs the matrix in RowMajor!
  Eigen::Matrix<double, 11, 3, Eigen::RowMajor> T;
  T << 7, 1, 2,   5, 6, 2,    4, 1, 7,    6, 7, 2,
       6, 4, 7,   6, 5, 0,    3, 6, 0,    8, 4, 3, 
       3, 4, 6,   8, 1, 4,    9, 1, 8;

  mglData xd(x.data(), x.size()),
          yd(y.data(), y.size()),
          Td(T.rows(), T.cols(), T.data());

  gr->SetRanges(0,1,0,1);
  gr->Grid("","h="); 
  gr->TriPlot(Td, xd, yd,"#b");
  gr->Plot(xd, yd, " r*");
  gr->Label(xd, yd,"%n"); // give each point an individual number
  gr->Axis();

  return;
}

int main()
{
  mglGraph gr;
  sample(&gr);
  gr.WriteEPS("triangulation.eps");

  return 0;
}
