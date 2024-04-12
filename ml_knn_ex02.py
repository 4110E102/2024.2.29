import numpy as np
from sklearn.neighbors import KNeighborsClassifier

X_train = np.array([[160,60], [170,70], [155,55],
                    [180,80],[165,50],[175,65]])
y_train = np.array(['男性','男性','女性','男性','女性','女性'])


knn_classifier = KNeighborsClassifier(n_neighbors=3)

knn_classifier.fit(X_train, y_train)

new_data_points = np.array([[170, 75],[162, 58], [172,68]])
predicted_labels = knn_classifier.predict(new_data_points)

for i, label in enumerate(predicted_labels):
    print(f"預測結果 {i+1}:{label}")