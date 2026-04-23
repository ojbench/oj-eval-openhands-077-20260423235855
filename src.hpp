#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

// CrossArray implementation for OJ Problem 1410

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;
        int* sizes;
        int maxLines;
        int currentLines;

        void deepCopy(const CrossArray& o) {
            maxLines = o.maxLines;
            currentLines = o.currentLines;
            arrays = new int*[maxLines];
            sizes = new int[maxLines];
            
            for (int i = 0; i < maxLines; i++) {
                if (i < currentLines && o.arrays[i] != nullptr) {
                    sizes[i] = o.sizes[i];
                    arrays[i] = new int[sizes[i]];
                    for (int j = 0; j < sizes[i]; j++) {
                        arrays[i][j] = o.arrays[i][j];
                    }
                } else {
                    arrays[i] = nullptr;
                    sizes[i] = 0;
                }
            }
        }

        void cleanup() {
            if (arrays != nullptr) {
                for (int i = 0; i < maxLines; i++) {
                    if (arrays[i] != nullptr) {
                        delete[] arrays[i];
                    }
                }
                delete[] arrays;
            }
            if (sizes != nullptr) {
                delete[] sizes;
            }
        }

    public:
        explicit CrossArray(int lines) {
            maxLines = lines;
            currentLines = 0;
            arrays = new int*[maxLines];
            sizes = new int[maxLines];
            for (int i = 0; i < maxLines; i++) {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }

        CrossArray(const CrossArray& o) {
            deepCopy(o);
        }

        CrossArray& WhichGreater(CrossArray& o) {
            int thisCount = 0;
            for (int i = 0; i < currentLines; i++) {
                thisCount += sizes[i];
            }
            
            int oCount = 0;
            for (int i = 0; i < o.currentLines; i++) {
                oCount += o.sizes[i];
            }
            
            if (thisCount >= oCount) {
                return *this;
            } else {
                return o;
            }
        }

        bool IsSame(const CrossArray& o) {
            return arrays == o.arrays;
        }

        bool InsertArrays(const int* Input, int size) {
            if (currentLines >= maxLines) {
                return false;
            }
            
            arrays[currentLines] = new int[size];
            sizes[currentLines] = size;
            for (int i = 0; i < size; i++) {
                arrays[currentLines][i] = Input[i];
            }
            currentLines++;
            return true;
        }

        void AppendArrays(const int* Input, int Line, int size) {
            int oldSize = sizes[Line];
            int newSize = oldSize + size;
            int* newArray = new int[newSize];
            
            for (int i = 0; i < oldSize; i++) {
                newArray[i] = arrays[Line][i];
            }
            for (int i = 0; i < size; i++) {
                newArray[oldSize + i] = Input[i];
            }
            
            delete[] arrays[Line];
            arrays[Line] = newArray;
            sizes[Line] = newSize;
        }

        void DoubleCrossLength() {
            int newMaxLines = maxLines * 2;
            int** newArrays = new int*[newMaxLines];
            int* newSizes = new int[newMaxLines];
            
            for (int i = 0; i < maxLines; i++) {
                newArrays[i] = arrays[i];
                newSizes[i] = sizes[i];
            }
            for (int i = maxLines; i < newMaxLines; i++) {
                newArrays[i] = nullptr;
                newSizes[i] = 0;
            }
            
            delete[] arrays;
            delete[] sizes;
            arrays = newArrays;
            sizes = newSizes;
            maxLines = newMaxLines;
        }

        const int* AtArray(int i) {
            return arrays[i];
        }

        int& At(int i, int j) {
            return arrays[i][j];
        }

        ~CrossArray() {
            cleanup();
        }
    };
}

#endif
