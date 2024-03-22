import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

height = np.array([61, 62, 63, 65, 66, 67, 68, 70, 72, 74])
age = np.array([23, 24, 27, 28, 29, 30, 31, 32, 35, 37])
weight = np.array([120, 125, 130, 135, 140, 145, 150, 155, 160, 165])

features = np.column_stack((height, age))

X_train, X_test, y_train, y_test = train_test_split(features, weight,
                                                    test_size = 0.2, random_state=0)

model = LinearRegression()

model.fit(X_train, y_train)

y_pred = model.predict(X_test)
# from sklearn.metrics import r2_score
# r2_test = r2_score(y_test, y_pred)
# print("R-squared for the test set: ", r2_test)

plt.figure(figsize=(14, 7))

plt.subplot(1, 2, 1)
plt.scatter(X_train[:, 0], y_train, color='blue', label='Train')
plt.scatter(X_test[:, 0], y_test, color='red', label='Test')
plt.xlabel('Height')
plt.ylabel('Weight')
plt.title('Relationship between Height and Weight')
plt.legend()

plt.subplot(1, 2, 2)
plt.scatter(X_train[:, 1], y_train, color='blue', label='Train')
plt.scatter(X_test[:, 1], y_test, color='red', label='Test')
plt.xlabel('Age')
plt.ylabel('Weight')
plt.title('Relationship between Age and Weight')
plt.legend()
