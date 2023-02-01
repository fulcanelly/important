public class Jumping {

    static int x_size = 200 * 100;
    static int y_size = 200 * 100;

    final int _x_size;
    final int _y_size;

    int[][] data;

    Jumping(int x, int y) {
        this._x_size = x;
        this._y_size = y;
        allocate();
    }

    void allocate() {
        data = new int[_x_size][_y_size];
    }

    void fill() {
        int k = 0;
        for (int j = 0; j < y_size; j++) {
            for (int i = 0; i < x_size; i++) {
                data[i][j] = k++;
            }
        }
    }


    int count() {
        int sum = 0;
        for (var j = 0; j < x_size; j++) {
            for (var i = 0; i < y_size; i++) {
               sum |= data[i][j];
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        var linear = new Jumping(x_size, y_size);
        linear.fill();
        System.out.println(linear.count());

    }

}
