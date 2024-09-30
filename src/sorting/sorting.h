#include <functional>

template <typename Element, typename Compare = std::less<Element>>
void bubble_sort(Element* arr, size_t size, Compare comp = Compare());

template <typename Element, typename Compare = std::less<Element>>
void bubble_sort(std::vector<Element>& v, Compare comp = Compare());

template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void bubble_sort(Iterator first, Iterator last, Compare comp = Compare());

template<typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void merge_sort(Iterator first, Iterator last, Compare comp = Compare());

template<typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void quick_sort(Iterator first, Iterator last, Compare comp = Compare());