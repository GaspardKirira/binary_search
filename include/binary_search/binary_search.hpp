#pragma once
#include <cstddef>
#include <vector>

namespace binary_search
{
  inline bool contains_sorted(const std::vector<std::size_t> &v, std::size_t key)
  {
    std::size_t lo = 0;
    std::size_t hi = v.size();

    while (lo < hi)
    {
      const std::size_t mid = lo + (hi - lo) / 2;

      if (v[mid] == key)
        return true;

      if (v[mid] < key)
        lo = mid + 1;
      else
        hi = mid;
    }

    return false;
  }

  inline std::size_t lower_bound_sorted(const std::vector<std::size_t> &v, std::size_t key)
  {
    std::size_t lo = 0;
    std::size_t hi = v.size();

    while (lo < hi)
    {
      const std::size_t mid = lo + (hi - lo) / 2;

      if (v[mid] < key)
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo;
  }

  inline std::size_t upper_bound_sorted(const std::vector<std::size_t> &v, std::size_t key)
  {
    std::size_t lo = 0;
    std::size_t hi = v.size();

    while (lo < hi)
    {
      const std::size_t mid = lo + (hi - lo) / 2;

      if (v[mid] <= key)
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo;
  }
}
