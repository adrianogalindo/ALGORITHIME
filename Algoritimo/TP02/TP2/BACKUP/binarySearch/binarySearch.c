int main()
{        
        int* tableau;
        int valeur


        int noComparaison = 1;

        int gauche = 0;
        int droit = strlen(tableau) - 1;
        while (gauche <= droit) {
            int index = (droit + gauche) / 2;
        if (tableau[index] == valeur) {
                return VRAI;
        }
        if (tableau[index] > valeur) {
            droit = index - 1;
        } else {
            gauche = index + 1;
        }
    }
    return FAUX;

}