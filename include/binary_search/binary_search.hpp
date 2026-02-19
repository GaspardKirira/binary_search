#pragma once
#include <cstddef>
#include <vector>

namespace binary_search
{
  /**
   * @brief Checks whether a sorted vector contains a given key.
   *
   * Performs a binary search on a sorted vector of std::size_t values.
   *
   * @param v   Sorted vector to search in (must be sorted in ascending order).
   * @param key Value to search for.
   * @return true  If the key exists in the vector.
   * @return false If the key is not found.
   *
   * @complexity O(log n)
   */
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

  /**
   * @brief Returns the index of the first element not less than key.
   *
   * Equivalent to std::lower_bound for sorted std::size_t vectors.
   *
   * @param v   Sorted vector (ascending order).
   * @param key Value to compare.
   * @return Index of the first element >= key.
   *         If all elements are smaller, returns v.size().
   *
   * @complexity O(log n)
   */
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

  /**
   * @brief Returns the index of the first element greater than key.
   *
   * Equivalent to std::upper_bound for sorted std::size_t vectors.
   *
   * @param v   Sorted vector (ascending order).
   * @param key Value to compare.
   * @return Index of the first element > key.
   *         If no such element exists, returns v.size().
   *
   * @complexity O(log n)
   */
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
