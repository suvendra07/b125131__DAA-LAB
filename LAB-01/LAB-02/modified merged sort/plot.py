import pandas as pd
import matplotlib.pyplot as plt

# 1. Read the CSV data
try:
    df = pd.read_csv('benchmark_results.csv')
except FileNotFoundError:
    print("Error: 'benchmark_results.csv' still not found.")
    df = pd.DataFrame() # Fallback

if not df.empty:
    # --- Professional Styling ---
    plt.style.use('seaborn-v0_8-whitegrid')
    fig, ax = plt.subplots(figsize=(10, 6))

    # 2. Plotting using 'N' instead of 'Size'
    ax.plot(df['N'], df['MergeSort_Time'], marker='o', label='Standard 2-Way Merge Sort', linewidth=2)
    ax.plot(df['N'], df['ModifiedMergeSort_Time'], marker='D', label='Modified 3-Way Merge Sort', linewidth=2)

    # 3. Formatting
    ax.set_title('Performance Comparison: 2-Way vs 3-Way Merge Sort', fontweight='bold')
    ax.set_xlabel('Array Size (N)')
    ax.set_ylabel('Execution Time (Seconds)')
    ax.legend()
    
    plt.show()
else:
    print("DataFrame is empty. Cannot plot.")