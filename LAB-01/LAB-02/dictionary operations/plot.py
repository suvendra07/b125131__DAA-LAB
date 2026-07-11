import pandas as pd
import matplotlib.pyplot as plt

try:
    df = pd.read_csv('results.csv')
except FileNotFoundError:
    print("Error: 'results.csv' not found. Please run the C program first.")
    exit(1)

operations = [
    'Time_Insert', 'Time_Search', 'Time_Max', 
    'Time_Min', 'Time_Pred', 'Time_Succ', 'Time_Delete'
]
op_titles = [
    'Insertion', 'Search', 'Maximum', 
    'Minimum', 'Predecessor', 'Successor', 'Deletion'
]

# Mapping the theoretical worst-case time complexities for each operation
complexities = {
    'Time_Insert': {
        'Unsorted_Array': 'O(1)', 'Sorted_Array': 'O(N)',
        'SLL_Unsorted': 'O(1)', 'SLL_Sorted': 'O(N)',
        'DLL_Unsorted': 'O(1)', 'DLL_Sorted': 'O(N)'
    },
    'Time_Search': {
        'Unsorted_Array': 'O(N)', 'Sorted_Array': 'O(log N)',
        'SLL_Unsorted': 'O(N)', 'SLL_Sorted': 'O(N)',
        'DLL_Unsorted': 'O(N)', 'DLL_Sorted': 'O(N)'
    },
    'Time_Max': {
        'Unsorted_Array': 'O(N)', 'Sorted_Array': 'O(1)',
        'SLL_Unsorted': 'O(N)', 'SLL_Sorted': 'O(N)',
        'DLL_Unsorted': 'O(N)', 'DLL_Sorted': 'O(1)'
    },
    'Time_Min': {
        'Unsorted_Array': 'O(N)', 'Sorted_Array': 'O(1)',
        'SLL_Unsorted': 'O(N)', 'SLL_Sorted': 'O(1)',
        'DLL_Unsorted': 'O(N)', 'DLL_Sorted': 'O(1)'
    },
    'Time_Pred': {
        'Unsorted_Array': 'O(N)', 'Sorted_Array': 'O(1)',
        'SLL_Unsorted': 'O(N)', 'SLL_Sorted': 'O(N)',
        'DLL_Unsorted': 'O(N)', 'DLL_Sorted': 'O(1)'
    },
    'Time_Succ': {
        'Unsorted_Array': 'O(N)', 'Sorted_Array': 'O(1)',
        'SLL_Unsorted': 'O(N)', 'SLL_Sorted': 'O(1)',
        'DLL_Unsorted': 'O(N)', 'DLL_Sorted': 'O(1)'
    },
    'Time_Delete': {
        'Unsorted_Array': 'O(1)', 'Sorted_Array': 'O(N)',
        'SLL_Unsorted': 'O(N)', 'SLL_Sorted': 'O(N)',
        'DLL_Unsorted': 'O(1)', 'DLL_Sorted': 'O(1)'
    }
}

# --- Academic / Whitepaper Styling Configuration ---
plt.rcParams.update({
    'font.family': 'serif',           # Elegant, formal font
    'axes.titlesize': 14,
    'axes.labelsize': 12,
    'xtick.labelsize': 11,
    'ytick.labelsize': 11,
    'legend.fontsize': 10,
    'figure.titlesize': 20,
    'figure.titleweight': 'bold',
    'text.color': '#1a1a1a',          # Slightly softer than pure black
    'axes.labelcolor': '#1a1a1a'
})

data_structures = df['Data_Structure'].unique()

# Distinct markers: Cross, Thin Diamond, Star, Plus, Hexagon, Triangle Down
markers = ['X', 'd', '*', 'P', 'h', 'v']

# High contrast bold palette: Crimson, Teal, Deep Navy, Coral, Amethyst, Cerulean
colors = ['#E63946', '#2A9D8F', '#264653', '#F4A261', '#9B5DE5', '#00B4D8']

# Set an off-white background color for the whole figure
bg_color = '#F9F9FB'
fig, axes = plt.subplots(nrows=2, ncols=4, figsize=(22, 11), facecolor=bg_color)
fig.suptitle('Time Complexity Analysis of Dictionary Operations', y=0.96)
axes = axes.flatten()

for i, op in enumerate(operations):
    ax = axes[i]
    ax.set_facecolor(bg_color) # Match subplot background to figure
    
    for j, ds in enumerate(data_structures):
        subset = df[df['Data_Structure'] == ds]
        
        complexity_label = complexities[op].get(ds, 'O(?)')
        display_name = ds.replace('_', ' ')
        legend_label = f"{display_name} ({complexity_label})"
        
        ax.plot(subset['N'], subset[op], 
                label=legend_label, 
                marker=markers[j], 
                color=colors[j],
                linewidth=1.8,             # Thinner, elegant lines
                markersize=8,              # Larger markers
                markeredgecolor='black',   # Black outline around markers
                markeredgewidth=0.7,       # Outline thickness
                alpha=0.9)
    
    # Subplot titles and labels
    ax.set_title(f'{op_titles[i]} Time', fontweight='bold', pad=10)
    ax.set_xlabel('Number of Elements (N)')
    ax.set_ylabel('Execution Time (sec)')
    
    # Dotted grid for a cleaner background
    ax.grid(True, linestyle=':', linewidth=1.2, color='#D3D3D3', alpha=0.8)
    
    # Minimalist spines
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.spines['left'].set_linewidth(1.2)
    ax.spines['bottom'].set_linewidth(1.2)
    
    # Legend with a crisp border
    ax.legend(loc='upper left', frameon=True, fancybox=False, 
              edgecolor='black', framealpha=1.0)

# Hide the last unused subplot entirely
axes[7].axis('off')

plt.tight_layout(rect=[0, 0.03, 1, 0.94])
plt.savefig('q1_plot_results_academic.png', dpi=300, bbox_inches='tight', facecolor=fig.get_facecolor())
print("Plot successfully generated and saved as 'q1_plot_results_academic.png'.")
plt.show()