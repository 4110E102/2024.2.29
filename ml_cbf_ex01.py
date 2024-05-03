from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

movies = {
    "movie1": "A Love story set in New York",
    "movie2": "A Sci-Fi about aliens in New York",
    "movie3": "A documentary about the history of New York",
    "movie4": "A comedy set in Toronto"
}

vectorizer = TfidfVectorizer(stop_words='english')
tfidf_matrix = vectorizer.fit_transform(movies.values())

cosine_sim = cosine_similarity(tfidf_matrix, tfidf_matrix)

movie_index = 0
similar_movies = list(enumerate(cosine_sim[movie_index]))

similar_movies_sorted = sorted(similar_movies, key=lambda x: x[1], reverse=True)
for i in similar_movies_sorted[1:]:
    print(f"{list(movies.keys())[i[0]]} with similarity score {i[1]}")