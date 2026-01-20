#include <binary_search/binary_search.hpp>
#include <iostream>
#include <vector>

int main()
{
  std::vector<std::size_t> v{0, 1, 2, 3, 4};

  const bool ok0 = binary_search::contains_sorted(v, 3);
  const bool ok1 = !binary_search::contains_sorted(v, 99);

  const std::size_t lb = binary_search::lower_bound_sorted(v, 3);
  const std::size_t ub = binary_search::upper_bound_sorted(v, 3);

  std::cout << "contains(3)=" << (ok0 ? "true" : "false") << "\n";
  std::cout << "contains(99)=" << (ok1 ? "true" : "false") << "\n";
  std::cout << "lower_bound(3)=" << lb << "\n";
  std::cout << "upper_bound(3)=" << ub << "\n";

  const bool pass = ok0 && ok1 && (lb == 3) && (ub == 4);
  return pass ? 0 : 1;
}
