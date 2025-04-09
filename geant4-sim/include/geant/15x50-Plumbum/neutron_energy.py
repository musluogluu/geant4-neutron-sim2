import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# CSV dosyasını oku
df = pd.read_csv("neutron_energy.csv")

# Sadece enerji sütunu varsa, ismini sadeleştirelim
df.columns = ["Energy"]

# Sayıya dönüştür (bozuk verileri NaN yapar)
df["Energy"] = pd.to_numeric(df["Energy"], errors="coerce")

# Geçersiz (NaN) verileri at
df = df.dropna()

# KDE grafiği çiz
plt.figure(figsize=(10, 6))
sns.kdeplot(df["Energy"], fill=True, color="darkblue", linewidth=2)
plt.title("Neutron Energy Density Estimation", fontsize=14)
plt.xlabel("Energy [MeV]")
plt.ylabel("Density")
plt.grid(True)
plt.tight_layout()
plt.show()
