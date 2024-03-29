import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression


height = np.array([61, 62, 63, 65, 66, 67, 68, 70, 72, 74])
age = np.array([23, 24, 27, 28, 29, 30, 31, 32, 35, 37])

weight = np.array([120, 125, 130, 135, 140, 145, 150, 155, 160, 165])

features = np.column_stack((height, age))

X_temp, X_test, y_temp, y_test = train_test_split(features, weight,
                                                    test_size = 0.2, random_state=0)
X_train, X_val, y_train, y_val = train_test_split(X_temp, y_temp,
                                                    test_size = 0.25, random_state=0)

model = LinearRegression()

model.fit(X_train, y_train)

y_val_pred = model.predict(X_val)
# from sklearn.metrics import r2_score
# r2_test = r2_score(y_test, y_pred)
# print("R-squared for the test set: ", r2_test)
from sklearn.metrics import r2_score
r2_val = r2_score(y_val, y_val_pred)
print("R-squared for the validation set: ",r2_val)


y_pred = model.predict(X_test)

r2_test = r2_score(y_test, y_pred)
print("R-squared for the test set: ",r2_test)