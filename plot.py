import matplotlib.pyplot as plt
import networkx as nx

# Create a directed graph
G = nx.DiGraph()

# Add nodes and edges for each layer
G.add_edges_from([
    ("Main Application", "HAL Layer"),
    ("HAL Layer", "Servo_Interface.h/.c"),
    ("Servo_Interface.h/.c", "MCAL Layer"),
    ("MCAL Layer", "GPIO_Interface"),
    ("MCAL Layer", "RCC_Interface"),
    ("MCAL Layer", "TIMER1_Interface"),
    ("MCAL Layer", "UART_Interface"),
    ("GPIO_Interface", "GPIO_Driver"),
    ("RCC_Interface", "RCC_Driver"),
    ("TIMER1_Interface", "TIMER1_Driver"),
    ("UART_Interface", "UART_Driver"),
    ("GPIO_Driver", "LIB Layer: Common Utilities"),
    ("RCC_Driver", "LIB Layer: Common Utilities"),
    ("TIMER1_Driver", "LIB Layer: Common Utilities"),
    ("UART_Driver", "LIB Layer: Common Utilities"),
    ("DMA_Interface", "LIB Layer: Common Utilities"),
    ("NVIC_Interface", "LIB Layer: Common Utilities"),
    ("EXTI_Interface", "LIB Layer: Common Utilities"),
    ("SYSTICK_Interface", "LIB Layer: Common Utilities"),
    ("LIB Layer: Common Utilities", "ellithy_delay.h, BIT_MATH.h, Types.h")
])

# Define node positions for top-to-bottom layout
pos = {
    "Main Application": (0, 10),
    "HAL Layer": (0, 8),
    "Servo_Interface.h/.c": (0, 6),
    "MCAL Layer": (0, 4),
    "GPIO_Interface": (-3, 2),
    "RCC_Interface": (-1, 2),
    "TIMER1_Interface": (1, 2),
    "UART_Interface": (3, 2),
    "GPIO_Driver": (-3, 0),
    "RCC_Driver": (-1, 0),
    "TIMER1_Driver": (1, 0),
    "UART_Driver": (3, 0),
    "DMA_Interface": (-4, -2),
    "NVIC_Interface": (-2, -2),
    "EXTI_Interface": (0, -2),
    "SYSTICK_Interface": (2, -2),
    "LIB Layer: Common Utilities": (0, -4),
    "ellithy_delay.h, BIT_MATH.h, Types.h": (0, -6)
}

# Draw the graph
plt.figure(figsize=(12, 10))
nx.draw(G, pos, with_labels=True, node_size=3000, node_color="#90CAF9", font_size=10, font_weight='bold', arrowsize=20, arrowstyle='->', edge_color='gray')
plt.title("Top-to-Bottom Layered Architecture")
plt.show()
