#ifndef WORDS_H
#define WORDS_H


typedef struct {
    char *word;
    char *hint;
} Node;

typedef struct {
    char* category;
    Node* nodes;
    int numNodes;
} Category;

int numCategories = 6;

Node animals[] = {
    {"Elephant", "Largest land animal"},
    {"Tiger", "Large cat with stripes"},
    {"Giraffe", "Tallest animal with a long neck"},
    {"Lion", "King of the jungle"},
    {"Monkey", "Primate known for swinging on trees"},
    {"Dolphin", "Smart marine mammal"},
    {"Kangaroo", "Hops on two legs"},
    {"Zebra", "Striped horse-like animal"},
    {"Panda", "Black and white bear"},
    {"Bear", "Large mammal with fur"},
    {"Rhino", "Large herbivorous mammal with a horn"},
    {"Hippo", "Large herbivorous mammal with a big mouth"},
    {"Crocodile", "Large reptile with a long snout"},
    {"Eagle", "Large bird of prey"},
    {"Octopus", "Sea creature with eight arms"}
};

Node fruits[] = {
    {"Strawberry", "Red fruit with seeds on the outside"},
    {"Pineapple", "Tropical fruit with spiky skin"},
    {"Watermelon", "Large green fruit with red flesh"},
    {"Kiwi", "Small brown fruit with green flesh"},
    {"Raspberry", "Small red fruit with many seeds"},
    {"Blueberry", "Small blue fruit"},
    {"Mango", "Tropical fruit with a sweet taste"},
    {"Papaya", "Tropical fruit with orange flesh"},
    {"Grapefruit", "Large citrus fruit"},
    {"Peach", "Fuzzy fruit with a pit"},
    {"Banana", "Yellow fruit with a curved shape"},
    {"Apple", "Common fruit with a core, also a tech company"},
    {"Orange", "Citrus fruit with a thick skin"},
    {"Plum", "Small sweet fruit"},
    {"Coconut", "Large fruit with a hard shell"}
};

Node countries[] = {
    {"Australia", "Country known for kangaroos and koalas"},
    {"Canada", "Northern neighbor of the United States"},
    {"Japan", "Country of the rising sun"},
    {"Brazil", "South American country known for soccer"},
    {"Germany", "European country known for beer and sausages"},
    {"Italy", "Country famous for pasta and pizza"},
    {"Argentina", "South American country known for tango"},
    {"India", "Country with a rich cultural heritage"},
    {"Mexico", "North American country known for tacos"},
    {"France", "European country known for fashion and cuisine"},
    {"China", "Most populous country in the world"},
    {"Spain", "European country known for bullfighting and flamenco"},
    {"Russia", "Largest country in the world by landmass"},
    {"South Africa", "Country known for its diverse wildlife and apartheid history"},
    {"Sweden", "Scandinavian country known for its welfare system"}
};

Node colors[] = {
    {"Magenta", "Bright purplish-red color"},
    {"Cyan", "Greenish-blue color"},
    {"Indigo", "Deep blue color"},
    {"Maroon", "Dark reddish-brown color"},
    {"Turquoise", "Blue-green color"},
    {"Lavender", "Pale purple color"},
    {"Coral", "Pinkish-orange color"},
    {"Amber", "Orange-yellow color"},
    {"Violet", "Purplish-blue color"},
    {"Crimson", "Deep red color"},
    {"Teal", "Greenish-blue color"},
    {"Olive", "Dark greenish-brown color"},
    {"Peach", "Pale pinkish-orange color"},
    {"Slate", "Dark bluish-gray color"},
    {"Sienna", "Reddish-brown color"}
};

Node professions[] = {
    {"Doctor", "Medical professional"},
    {"Engineer", "Builds and designs structures and machines"},
    {"Lawyer", "Provides legal advice and services"},
    {"Artist", "Creates visual or performing arts"},
    {"Chef", "Prepares and cooks food"},
    {"Pilot", "Flies aircraft"},
    {"Teacher", "Educates students"},
    {"Musician", "Plays musical instruments or sings"},
    {"Scientist", "Conducts scientific research"},
    {"Architect", "Designs buildings and structures"},
    {"Nurse", "Provides medical care and assistance"},
    {"Firefighter", "Fights fires and performs rescues"},
    {"Police Officer", "Enforces laws and maintains public order"},
    {"Astronaut", "Travels to space"},
    {"Veterinarian", "Treats and cares for animals"}
};

Node famous_brands[] = {
    {"Apple", "Tech company known for iPhones and Macs"},
    {"Google", "Internet search giant"},
    {"Amazon", "Online retail giant"},
    {"Microsoft", "Software company known for Windows"},
    {"Coca-Cola", "Popular cola brand"},
    {"Nike", "Just do it!"},
    {"Samsung", "Electronics company, not Apple"},
    {"Toyota", "Japanese automotive manufacturer"},
    {"McDonald's", "Global fast-food chain"},
    {"BMW", "German luxury automobile manufacturer"},
    {"Mercedes-Benz", "Luxury automobile manufacturer"},
    {"Adidas", "Sportswear and equipment company, not Nike"},
    {"Pepsi", "Soft drink and snack company"},
    {"Facebook", "Social media platform, started as a college network"},
    {"Volkswagen", "Automobile manufacturer, people's car"},
};

Category categories[] = {
    {"Animals", animals, 15},
    {"Fruits", fruits, 15},
    {"Countries", countries, 15},
    {"Colors", colors, 15},
    {"Professions", professions, 15},
    {"Famous Brands", famous_brands, 15}
};
#endif
