/** calcule la moyenne des notes contenues dans un fichier
 *  Format: chaque ligne est de la forme "<nom> <note>"
 *  @param nomFichier le nom du fichier
 *  @return la moyenne des notes
 **/
float moyenne(string nomFichier);

/** lit les notes contenues dans un fichier et en fait un tableau
 *  Format: chaque ligne est de la forme "<nom> <note>"
 *  @param nomFichier le nom du fichier
 *  @return un tableau contenant les notes
 **/
vector<int> lit_notes(string nomFichier);

/** compte le nombre de mots d'un fichier
 *  @param nomFichier le nom du fichier
 *  @return le nombre de mots contenus dans le fichier
 **/
int word_count(string nomFichier);

/** compte le nombre de lignes d'un fichier
 *  @param nomFichier le nom du fichier
 *  @return le nombre de lignes contenues dans le fichier
 **/
int line_count(string nomFichier);

/** affiche (sur la sortie standard) le contenu d'un fichier
 *  @param nomFichier le nom du fichier
 **/
void cat(string nomFichier);

/** copie le contenu d'un fichier dans un autre
 *  @param source le nom du fichier source
 *  @param destination le nom du fichier destination
 **/
void copy(string source, string destination);
