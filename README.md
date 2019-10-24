# push_swap
The purpose of this project is to sort a pile of integers using only a limited number of operations:
  Push: move the number on the top of the pile to a second pile.
  Swap: exchange the two elements at the top of a pile.
  Rotate: Take the element at the top of a pile and put it at the bottom.
  Raverse-rotate: Take the element at the bottom of a pile and put it at the top.
# Algorithm used :
  1.Determine the deciles of the pile.
  2.For each decile, starting from the smallest, push all the elements inferior to the decile to the second pile, and rotate the other ones.
  3. Push back the elements to the first pile in the descending order.

