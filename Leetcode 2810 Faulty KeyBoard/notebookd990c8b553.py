# -*- coding: utf-8 -*-
"""notebookd990c8b553

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/#fileId=https%3A//storage.googleapis.com/kaggle-colab-exported-notebooks/muhammadyasirraiyan/notebookd990c8b553.d15f17d4-2618-481d-9a8a-5a7716960ac9.ipynb%3FX-Goog-Algorithm%3DGOOG4-RSA-SHA256%26X-Goog-Credential%3Dgcp-kaggle-com%2540kaggle-161607.iam.gserviceaccount.com/20250407/auto/storage/goog4_request%26X-Goog-Date%3D20250407T063323Z%26X-Goog-Expires%3D259200%26X-Goog-SignedHeaders%3Dhost%26X-Goog-Signature%3D6d82938c158a31139417ae32936012165d195534a208a14d1ba1260ad72a2ad8e6b35da9724ed5e6fe24b095b2c7407a87bb8c1280482aad8c453dd03a2885c47de8e2422f7a9fe32f529d0e54c033d48a24f28cae880d96a16ec202fb3ee3bbc6a07680c0d538a76f28e534f4092a6a6b411a484c7515e0bfe9526808e6585dfd2b42768ca94c0ed086475be5c23680b0a9abbcb580d41295cde9944c5aa449df3ad6b3fdbf2c538243467bc6f1f150ded47614134827efcd085dbbb6275dfb9ed9b0d53f4bf71fd2192f7e1cc01b5bd88b0985d251795ec29f0463417bcef44ae9c3b7b3be16daceb54b78575882c0bdfd428f893783d288bdd0f727b2b3c0
"""

import matplotlib.pyplot as plt
import numpy as np

# Input size range (1 থেকে 100 পর্যন্ত)
input_sizes = np.arange(1, 101)

# Time complexity: O(n^2) যদি প্রতিটি ক্যারেক্টার 'i' হয়
time_complexity = input_sizes ** 2

# Space complexity: O(n)
space_complexity = input_sizes

# গ্রাফ প্লটিং
plt.figure(figsize=(10, 6))
plt.plot(input_sizes, time_complexity, label='Time Complexity O(n²)', color='crimson', linewidth=2)
plt.plot(input_sizes, space_complexity, label='Space Complexity O(n)', color='navy', linestyle='--', linewidth=2)

# টাইটেল ও লেবেল
plt.title('Time and Space Complexity of finalString Function', fontsize=14, fontweight='bold')
plt.xlabel('Input Size (n)', fontsize=12)
plt.ylabel('Operations / Memory Usage', fontsize=12)
plt.legend()
plt.grid(True)
plt.tight_layout()

# JPEG ফাইল হিসেবে সংরক্ষণ
plt.savefig("finalString_time_space_complexity.jpeg", format='jpeg')
plt.show()