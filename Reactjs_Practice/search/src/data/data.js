const data = [
    { "id": 1, "name": "Alice", "age": 25 },
    { "id": 2, "name": "Bob", "age": 30 },
    { "id": 3, "name": "Charlie", "age": 22 },
    { "id": 4, "name": "David", "age": 28 },
    { "id": 5, "name": "Eva", "age": 27 },
    { "id": 6, "name": "Frank", "age": 24 },
    { "id": 7, "name": "Grace", "age": 32 },
    { "id": 8, "name": "Helen", "age": 29 },
    { "id": 9, "name": "Ivan", "age": 26 },
    { "id": 10, "name": "Jessica", "age": 23 },
    { "id": 11, "name": "Kevin", "age": 31 },
    { "id": 12, "name": "Linda", "age": 28 },
    { "id": 13, "name": "Mike", "age": 25 },
    { "id": 14, "name": "Nina", "age": 29 },
    { "id": 15, "name": "Oscar", "age": 30 },
    { "id": 16, "name": "Pamela", "age": 27 },
    { "id": 17, "name": "Quincy", "age": 24 },
    { "id": 18, "name": "Ryan", "age": 26 },
    { "id": 19, "name": "Samantha", "age": 22 },
    { "id": 20, "name": "Thomas", "age": 33 },
    { "id": 21, "name": "Ursula", "age": 28 },
    { "id": 22, "name": "Victor", "age": 31 },
    { "id": 23, "name": "Wendy", "age": 25 },
    { "id": 24, "name": "Xavier", "age": 27 },
    { "id": 25, "name": "Yvonne", "age": 29 },
    { "id": 26, "name": "Zane", "age": 24 },
    { "id": 27, "name": "Ava", "age": 30 },
    { "id": 28, "name": "Benjamin", "age": 26 },
    { "id": 29, "name": "Caleb", "age": 23 },
    { "id": 30, "name": "Diana", "age": 32 },
    { "id": 31, "name": "Ethan", "age": 28 },
    { "id": 32, "name": "Fiona", "age": 25 },
    { "id": 33, "name": "George", "age": 27 },
    { "id": 34, "name": "Hannah", "age": 29 },
    { "id": 35, "name": "Isaac", "age": 24 },
    { "id": 36, "name": "Jane", "age": 30 },
    { "id": 37, "name": "Karl", "age": 26 },
    { "id": 38, "name": "Lily", "age": 23 },
    { "id": 39, "name": "Matthew", "age": 32 },
    { "id": 40, "name": "Natalie", "age": 28 },
    { "id": 41, "name": "Oliver", "age": 25 },
    { "id": 42, "name": "Penelope", "age": 27 },
    { "id": 43, "name": "Quinn", "age": 29 },
    { "id": 44, "name": "Robert", "age": 24 },
    { "id": 45, "name": "Sophia", "age": 30 },
    { "id": 46, "name": "Theodore", "age": 26 },
    { "id": 47, "name": "Uma", "age": 23 },
    { "id": 48, "name": "Vincent", "age": 32 },
    { "id": 49, "name": "Willow", "age": 28 },
    { "id": 50, "name": "Xander", "age": 25 },
    { "id": 51, "name": "Yasmine", "age": 27 },
    { "id": 52, "name": "Zara", "age": 29 },
    { "id": 53, "name": "Andrew", "age": 24 },
    { "id": 54, "name": "Bella", "age": 30 },
    { "id": 55, "name": "Carter", "age": 26 },
    { "id": 56, "name": "Daisy", "age": 23 },
    { "id": 57, "name": "Elijah", "age": 32 },
    { "id": 58, "name": "Freya", "age": 28 },
    { "id": 59, "name": "Gabriel", "age": 25 },
    { "id": 60, "name": "Hazel", "age": 27 },
    { "id": 61, "name": "Ian", "age": 24 },
    { "id": 62, "name": "Jasmine", "age": 30 },
    { "id": 63, "name": "Kevin", "age": 26 },
    { "id": 64, "name": "Luna", "age": 23 },
    { "id": 65, "name": "Mason", "age": 32 },
    { "id": 66, "name": "Nora", "age": 28 },
    { "id": 67, "name": "Oscar", "age": 25 },
    { "id": 68, "name": "Poppy", "age": 27 },
    { "id": 69, "name": "Quincy", "age": 29 },
    { "id": 70, "name": "Ruby", "age": 24 },
    { "id": 71, "name": "Samuel", "age": 30 },
    { "id": 72, "name": "Tessa", "age": 26 },
    { "id": 73, "name": "Ulysses", "age": 23 },
    { "id": 74, "name": "Violet", "age": 32 },
    { "id": 75, "name": "William", "age": 28 },
    { "id": 76, "name": "Xavier", "age": 25 },
    { "id": 77, "name": "Yara", "age": 27 },
    { "id": 78, "name": "Zane", "age": 29 },
    { "id": 79, "name": "Alice", "age": 24 },
    { "id": 80, "name": "Benjamin", "age": 30 },
    { "id": 81, "name": "Chloe", "age": 26 },
    { "id": 82, "name": "Daniel", "age": 23 },
    { "id": 83, "name": "Emma", "age": 32 },
    { "id": 84, "name": "Felix", "age": 28 },
    { "id": 85, "name": "Grace", "age": 25 },
    { "id": 86, "name": "Henry", "age": 27 },
    { "id": 87, "name": "Isla", "age": 29 },
    { "id": 88, "name": "Jack", "age": 24 },
    { "id": 89, "name": "Kate", "age": 30 },
    { "id": 90, "name": "Liam", "age": 26 },
    { "id": 91, "name": "Mia", "age": 23 },
    { "id": 92, "name": "Noah", "age": 32 },
    { "id": 93, "name": "Olivia", "age": 28 },
    { "id": 94, "name": "Peter", "age": 25 },
    { "id": 95, "name": "Quinn", "age": 27 },
    { "id": 96, "name": "Rose", "age": 29 },
    { "id": 97, "name": "Simon", "age": 24 },
    { "id": 98, "name": "Tara", "age": 30 },
    { "id": 99, "name": "Uma", "age": 26 },
    { "id": 100, "name": "Vincent", "age": 23 }
]

export default data;