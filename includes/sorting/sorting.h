#ifndef SORTING_H
#define SORTING_H

#include <functional>
#include <iterator>
#include <vector>

template <typename Element, typename Compare = std::less<Element>>
void bubble_sort(Element* arr, size_t size, Compare comp = Compare()) {
    for (size_t i = 0; i + 1 < size; ++i) {
        for (size_t j = 0; j + 1 < size - i; ++j) {
            if (!comp(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename Element, typename Compare = std::less<Element>>
void bubble_sort(std::vector<Element>& v, Compare comp = Compare()) {
    for (int i = 0; i + 1 < v.size(); ++i) {
        for (int j = 0; j + 1 < v.size() - i; ++j) {
            if (!comp(v[j], v[j + 1])) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void bubble_sort(Iterator first, Iterator last, Compare comp = Compare()) {
    if (first == last) {
        return;
    }

    bool is_swapped;
    do {
        is_swapped = false;
        for (auto it = first; std::next(it) != last; ++it) {
            if (!comp(*it, *std::next(it))) {
                std::iter_swap(it, std::next(it));
                is_swapped = true;
            }
        }
        --last;
    } while (is_swapped);
}

template<typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void merge_sort(Iterator first, Iterator last, Compare comp = Compare()) {
    auto dist = std::distance(first, last);
    if (dist > 1) {
        auto mid = first + dist / 2;
        merge_sort(first, mid);
        merge_sort(mid, last);

        std::vector<typename std::iterator_traits<Iterator>::value_type> tmp;
        auto it = std::back_inserter(tmp);
        auto left = first;
        auto right = mid;
        while (left != mid || right != last) {
            if (left == mid) {
                *it = *right++;
            } else if (right == last) {
                *it = *left++;
            } else if (comp(*left, *right)) {
                *it = *left++;
            } else {
                *it = *right++;
            }
        }

        std::copy(tmp.begin(), tmp.end(), first);
    }
}

template<typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void quick_sort(Iterator first, Iterator last, Compare comp = Compare()) {
    if (first == last || std::next(first) == last) {
        return;
    }

    auto pivot = first;
    for (auto it = std::next(first); it != last; ++it) {
        if (!comp(*first, *it)) {
            std::iter_swap(it, ++pivot);
        }
    }
    std::iter_swap(first, pivot);

    quick_sort(first, pivot);
    quick_sort(std::next(pivot), last);
}

#endif