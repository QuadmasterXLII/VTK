//
// Define cell array
//
#ifndef __vlCellList_h
#define __vlCellList_h

struct vlCell {
    short type;
    int loc;
};

class vlCellList {
public:
  vlCellList() : Array(0),Size(0),MaxId(-1),Extend(1000) {};
  vlCellList(const int sz, const int ext);
  ~vlCellList();
  char *GetClassName() {return "vlCellList";};
  vlCell &GetCell(const int id) {return this->Array[id];};
  short GetCellType(const int id) {return this->Array[id].type;};
  int GetCellLoc(const int id) {return this->Array[id].loc;};
  void InsertCell(const int id, const short type, const int loc);
  int InsertNextCell(const short type, const int pos);
  void Squeeze();
  void Reset();

private:
  vlCell *Array;   // pointer to data
  int Size;       // allocated size of data
  int MaxId;     // maximum index inserted thus far
  int Extend;     // grow array by this point
  vlCell *Resize(const int sz);  // function to resize data
};

#endif
