import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

csv_files = [
    "15x30-Tungsten/neutron_energy.csv",
    "15x60-Tungsten/neutron_energy.csv",
    "15x50-Plumbum/neutron_energy.csv",
    "15x60-Plumbum/neutron_energy.csv",
    "15x60-Copper/neutron_energy.csv"
]

all_data = pd.DataFrame()

for file in csv_files:
    df = pd.read_csv(file)
    df["Energy[MeV]"] = df["Energy[MeV]"].astype(str).str.replace(",", ".")
    df["Energy[MeV]"] = pd.to_numeric(df["Energy[MeV]"], errors="coerce")
    df = df.dropna()

    # 0.001 – 100 MeV arası verileri al
    df = df[(df["Energy[MeV]"] > 1e-3) & (df["Energy[MeV]"] <= 1e3)]

    label = file.split("/")[0]
    df["Source"] = label
    all_data = pd.concat([all_data, df])

# Grafik çizimi
plt.figure(figsize=(10, 6))
sns.histplot(
    data=all_data,
    x="Energy[MeV]",
    hue="Source",
    element="step",
    stat="density",
    common_norm=False,
    bins=200,
    log_scale=(True, False),
    fill=False,
    linewidth=2.0,
    palette="Dark2"
)

plt.xlim(1e-3, 1e3)  # X ekseni: 0.001 – 100 MeV
plt.title("Neutron Energy Distribution (0.001–100 MeV)")
plt.xlabel("Energy (MeV) [Log]")
plt.ylabel("Density")
plt.grid(True, which="both", ls="--", lw=0.5)
plt.tight_layout()
plt.show()
