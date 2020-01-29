void insertionSort(list<Data *> &l)
{
  list<Data *>::iterator begin = l.begin();
  list<Data *>::iterator end = l.end();
  list<Data *>::iterator it;

  for (list<Data *>::iterator it2 = next(begin, 1); it2 != end; it2++)
  {
    Data* temp = *it2;
    for (it = it2; (it != begin) && (comparatorT12(temp, *(prev(it, 1)))); it--) {
      *it = *(prev(it, 1));
    }
    begin++;
  }
}
