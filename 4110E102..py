import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

#Sample data
height = np.array([61,62,63,65,66,67,68,70,72,74]).reshape((-1,1))
weight = np.array([120,125,130,135,140,145, 150,155,160,165])

""" Split the data into training and test sets
    use height as a feature, and use weight as a target variable
"""
X_train, X_test, y_train, y_teat = train_test_split(height, weight,
                                                    test_size=0.2, random_state=0)

model = LinearRegression()

model.fit(X_train,y_train)

y_pred = model.predict(X_test)


plt.scatter(X_train, y_train, color = 'red')
plt.plot(X_train, model.predict(X_train), color = 'blue')
plt.title('Weight vs Height (Training set)')
plt.xlabel('Height')
plt.ylabel('Weight')

plt.show()

plt.scatter(X_test, y_teat, color = 'red')
plt.plot(X_test, y_pred, color = 'blue')
plt.title('Weight vs Height (Test set)')
plt.xlabel('Height')
plt.ylabel('Weight')

plt.show()