import sys
import numpy as np
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QVBoxLayout, QWidget, QLabel, QMessageBox
from PyQt5.QtGui import QPainter, QPen
from PyQt5.QtCore import Qt, QPoint

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Graph Drawer")
        
        # Create the canvas and buttons
        self.canvas = Canvas()
        self.generate_button = QPushButton("Generate Adjacency Matrix")
        self.generate_button.clicked.connect(self.generate_adjacency_matrix)
        self.clear_button = QPushButton("Clear")
        self.clear_button.clicked.connect(self.clear_canvas)
        self.quit_button = QPushButton("Quit")
        self.quit_button.clicked.connect(self.quit_application)
        
        # Labels to display adjacency matrix and gold value
        self.matrix_label = QLabel()
        self.gold_label = QLabel()
        
        # Layout
        layout = QVBoxLayout()
        layout.addWidget(self.canvas)
        layout.addWidget(self.generate_button)
        layout.addWidget(self.clear_button)
        layout.addWidget(self.quit_button)
        layout.addWidget(self.matrix_label)
        layout.addWidget(self.gold_label)

        # Container widget
        container = QWidget()
        container.setLayout(layout)
        
        self.setCentralWidget(container)
    
    def generate_adjacency_matrix(self):
        matrix = self.canvas.get_adjacency_matrix()
        np.save('matrix.npy', matrix)
        
        # Print the matrix to console
        matrix_str = "\n".join([" ".join(map(str, row)) for row in matrix])
        self.matrix_label.setText("Adjacency Matrix:\n" + matrix_str)
        
        # Calculate and display gold value
        result = triangle_counter(matrix)
        self.gold_label.setText("Gold: " + str(result))
    
    def clear_canvas(self):
        self.canvas.clear()
        self.matrix_label.clear()
        self.gold_label.clear()

    def quit_application(self):
        QApplication.quit()

class Canvas(QWidget):
    def __init__(self):
        super().__init__()
        self.nodes = []
        self.edges = []
        self.setMinimumSize(400, 400)
    
    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.add_node(event.pos())
        elif event.button() == Qt.RightButton:
            self.add_edge(event.pos())
        self.update()
    
    def add_node(self, position):
        if len(self.nodes) < 30:
            self.nodes.append((position.x(), position.y()))
        else:
            QMessageBox.warning(self, "Node Limit Reached", "You can only add up to 30 nodes.")
    
    def add_edge(self, position):
        if len(self.nodes) > 0:
            closest_node = min(self.nodes, key=lambda node: (node[0] - position.x()) ** 2 + (node[1] - position.y()) ** 2)
            self.edges.append((self.nodes[-1], closest_node))
    
    def paintEvent(self, event):
        painter = QPainter(self)
        pen = QPen(Qt.blue, 2, Qt.SolidLine)
        painter.setPen(pen)
        
        for node in self.nodes:
            painter.drawEllipse(QPoint(node[0], node[1]), 5, 5)
        
        for edge in self.edges:
            painter.drawLine(QPoint(edge[0][0], edge[0][1]), QPoint(edge[1][0], edge[1][1]))
    
    def get_adjacency_matrix(self):
        n = len(self.nodes)
        matrix = np.zeros((n, n), dtype=int)
        node_index = {node: i for i, node in enumerate(self.nodes)}
        for edge in self.edges:
            i, j = node_index[edge[0]], node_index[edge[1]]
            if i == j:
                continue
            matrix[i][j] = 1
            matrix[j][i] = 1  # Assuming undirected graph
        return matrix
    
    def clear(self):
        self.nodes = []
        self.edges = []
        self.update()

def triangle_counter(matrix):
    # Raise each element to the power of 3
    result = np.matmul(np.matmul(matrix, matrix), matrix)
    
    # Multiply by the diagonal elements
    result = np.trace(result)
    
    # Divide by 6
    result /= 6
    
    return result

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec_()

print("run app")