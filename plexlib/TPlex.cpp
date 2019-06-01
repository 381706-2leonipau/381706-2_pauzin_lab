#include <TPlex.h>

TPoint * TPlex::Show(TPlex * p)
{
  TPlex* lp = dynamic_cast<TPlex*>(p->left);
  TPlex* rp = dynamic_cast<TPlex* > (p->right);
  TPoint* tmp_l;
  TPoint* tmp_r;
  if (lp == NULL)
    tmp_l = p->left;
  else
    tmp_l = Show(lp);
  if (rp == NULL)
    tmp_r = p->right;
  else
    tmp_r = Show(rp);
  cout << "Line: ";
  tmp_l->Show();
  cout << " - ";
  tmp_r->Show();
  cout << endl;
  return tmp_r;
}

TPlex::TPlex()
{
  left = NULL;
  right = NULL;
}

TPlex::TPlex(TPlex & cp)
{
  TPlex* lBuff = dynamic_cast<TPlex*>(cp.left);
  TPlex* rBuff = dynamic_cast<TPlex*>(cp.right);
  if (lBuff != NULL)
    left = new TPlex(*lBuff);
  else
    left = new TPoint(*cp.left);
  if (rBuff != NULL)
    right = new TPlex(*rBuff);
  else
    right = new TPoint(*cp.right);
}

TPlex::TPlex(TPoint * l, TPoint * r)
{
  TPlex* lBuff = dynamic_cast<TPlex*>(l);
  TPlex* rBuff = dynamic_cast<TPlex*>(r);
  if (lBuff != NULL)
    left = new TPlex(*lBuff);
  else
    left = new TPoint(*l);
  if (rBuff != NULL)
    right = new TPlex(*rBuff);
  else
    right = new TPoint(*r);
}

TPlex & TPlex::operator+=(TLine & line)
{
  if (left == NULL && right == NULL)
  {
    left = line.GetA();
    right = line.GetB();
  }
  else
  {
    TListStack<TPoint*> st;
    TListStack<TPlex*> parentSt;
    st.Put(left);
    st.Put(right);
    parentSt.Put(this);
    parentSt.Put(this);
    bool flag = true;
    while (flag)
    {
      TPoint* buff = st.Get();
      TPlex* parentBuff = parentSt.Get();
      if (*buff != *line.GetA() && *buff != *line.GetB())
      {
        TPlex* pl = dynamic_cast<TPlex*>(buff);
        if (pl != 0)
        {
          st.Put(pl->GetLeft());
          st.Put(pl->GetRight());
          parentSt.Put(pl);
          parentSt.Put(pl);
        }
      }
      else if (*buff == *line.GetA())
      {
        flag = false;
        if (*buff == *parentBuff->left)
        {
          parentBuff->left = new TPlex(line.GetB(), line.GetA());
        }
        else
        {
          parentBuff->right = new TPlex(line.GetB(), line.GetA());
        }
      }
      else
      {
        flag = false;
        if (*buff == *parentBuff->left)
        {
          parentBuff->left = new TPlex(line.GetA(), line.GetB());
        }
        else
        {
          parentBuff->right = new TPlex(line.GetA(), line.GetB());
        }
      }
    }
  }
  return *this;
}

TPoint * TPlex::GetLeft()
{
  return left;
}

TPoint * TPlex::GetRight()
{
  return right;
}

void TPlex::SetLeft(TPoint * l)
{
  left = l;
}

void TPlex::SetRight(TPoint *r)
{
  right = r;
}

void TPlex::Show()
{
  Show(this);
}

