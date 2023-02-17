/*
 * File: 'arrays.h'.
 * Author: Fábio Neto (ist1104126).
 * Description: Array utilities.
 */

#ifndef _ARRAYS_H_
#define _ARRAYS_H_

/*
 * Adds the element E to the vector VEC of size SZ using the function CMP as the comparator.
 */
#define sorted_array_add(E, VEC, SZ, COMP)       \
    int _i = (SZ);                               \
    while ((_i-- > 0) && (COMP(VEC[_i], E) > 0)) \
        VEC[_i+1] = VEC[_i];                     \
    VEC[_i+1] = E;

/*
 * Searches for an element using KEY in the vector VEC of size SZ,
 * using the function CMP as the comparator and storing the result
 * in the variable POS, if found.
 */
#define binary_search(KEY, VEC, SZ, CMP, POS)     \
    int _cmp, _mid, _left = 0, _right = (SZ);     \
    if (_right) {                                 \
        while (_left+1 < _right) {                \
            _mid = (_left+_right)/2;              \
            _cmp = CMP(VEC[_mid], KEY);           \
            if (!_cmp) {                          \
                POS = _mid;                       \
                _left = -1;                       \
                break;                            \
            }                                     \
            if (_cmp < 0) _left = _mid;           \
            else _right = _mid;                   \
        }                                         \
        if (_left != -1 && !CMP(VEC[_left], KEY)) \
            POS = _left;                          \
    }

#endif