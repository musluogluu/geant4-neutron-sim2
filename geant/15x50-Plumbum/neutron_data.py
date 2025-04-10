import pandas as pd
import matplotlib.pyplot as plt

# CSV dosyasını oku
df = pd.read_csv('neutron_data.csv')  # dosya adını gerektiği gibi değiştir

# Histogram (çubuk grafik) çizimi
plt.figure(figsize=(14, 6))
plt.bar(df['AngleBin'], df['Count'], color='skyblue', edgecolor='black')

plt.title('Neutron / Angle')
plt.xlabel('AngleBin')
plt.ylabel('Count')
plt.grid(axis='y', linestyle='--', alpha=0.7)

plt.tight_layout()
plt.show()
