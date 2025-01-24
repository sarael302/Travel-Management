#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class agenceVoyage; 
class Excursion;
class date {
public:
    int jrs;
    int mois;
    int annee;

    date(int j = 27, int m = 12, int a = 2023) {
        if (j <= 31 && m <= 12) {
            jrs = j;
            mois = m;
            annee = a;
        } else {
            cout << "Date invalide" << endl;
        }
    }
};

class Destination {
private:
    string nomDestination;
    string description;
    double coutMoyenVoyage;

public:
    Destination() {}

    Destination(string nomDestination, string description, double coutMoyenVoyage) :
        nomDestination(nomDestination), description(description), coutMoyenVoyage(coutMoyenVoyage) {}

    string getNomDestination()const  {
        return nomDestination;
    }

    string getDescription()const  {
        return description;
    }

    double getcoutMoyenVoyage() const {
        return coutMoyenVoyage;
    }

    void setNomDestination(string nomDestination) {
        this->nomDestination = nomDestination;
    }

    void setDescription(string description) {
        this->description = description;
    }

    void setcoutMoyenVoyage(double coutMoyenVoyage) {
        this->coutMoyenVoyage = coutMoyenVoyage;
    }

    void afficherDetailsDestination() const {
        cout << "Nom de la destination : " << nomDestination << endl;
        cout << "Description : " << description << endl;
        cout << "Coût moyen du voyage : " << coutMoyenVoyage << " Dirhams" << endl;
    }
};
class GuideTouristique;
class Voyage {
protected:
    int IdV;
    Destination destination;
    date dateDepart;
    date dateRetour;
    double Prix;
    int nbPlacesDisponible;
	vector<Excursion> excursions;
	 GuideTouristique* guide;
public:
    Voyage() {}
    Voyage(int IdV,Destination destination, date dateDepart, date dateRetour, double Prix, int nbPlacesDisponible) :
        IdV(IdV), destination(destination), dateDepart(dateDepart), dateRetour(dateRetour), Prix(Prix), nbPlacesDisponible(nbPlacesDisponible) {}



    vector<Excursion>& getExcursions() {
        return excursions;
    }

void reserverGuide(GuideTouristique* guideToReserve) {
        guide = guideToReserve;
    }
    int getIdV() const {
        return IdV;
    }

    void setIdV(int IdV) {
        this->IdV = IdV;
    }
    Destination getDestination() const {
        return destination;
    }

    void reserverPlace()  {
        if (nbPlacesDisponible > 0) {
                cout << "Place réservée pour le voyage avec identifiant " << IdV << endl;
                nbPlacesDisponible--;
            }
         else {
            cout << "Désolé, il n'y a plus de places disponibles pour ce voyage." << endl;
        }
    }

    void annulerReservation() {
        if (nbPlacesDisponible > 10) { // annulation possible si ya - 10 places disponibles
            cout << "Réservation annulée pour le voyage avec identifiant " << IdV << endl;
            nbPlacesDisponible++;
        } else {
            cout << "Impossible d'annuler la réservation." << endl;
        }
    }

     virtual void afficher() const {

    cout << "Identifiant du voyage : " << IdV << endl;
    cout << "Le nom de la destination : " << destination.getNomDestination() <<", sa description : "
         <<destination.getDescription()<<", et le cout moyen : "<<destination.getcoutMoyenVoyage()<< endl;
    cout << "Date de départ : " << dateDepart.jrs << "/" << dateDepart.mois << "/" << dateDepart.annee << endl;
    cout << "Date de retour : " << dateRetour.jrs << "/" << dateRetour.mois << "/" << dateRetour.annee << endl;
    cout << "Prix : " << Prix << " Dirhams" << endl;
    cout << "Nombre de places disponibles : " << nbPlacesDisponible << endl;
      
}


    void saisir() {
        cout << "Saisir les informations pour le voyage : " << endl;
        cout << "Identifiant du voyage : ";
        cin >> IdV;
        string nomDestination;
        cout << "Le nom de la destination : ";
        cin >> nomDestination;
        destination.setNomDestination(nomDestination);

        string descriptionDestination;
        cout << "La description de la destination : ";
        cin>>descriptionDestination;
        destination.setDescription(descriptionDestination);

    double coutMoyen;
    cout << "Le cout moyen de la destination : ";
    cin >> coutMoyen;
    destination.setcoutMoyenVoyage(coutMoyen);
        cout << "Date de départ (jj mm aaaa) : ";
        cin >> dateDepart.jrs >> dateDepart.mois >> dateDepart.annee;
        cout << "Date de retour (jj mm aaaa) : ";
        cin >> dateRetour.jrs >> dateRetour.mois >> dateRetour.annee;
        cout << "Prix : ";
        cin >> Prix;
        cout << "Nombre de places disponibles : ";
        cin >> nbPlacesDisponible;
    }
    void ajouterExcursion(const Excursion& excursion) {
        excursions.push_back(excursion);
    }
};
class agenceVoyage;
class Client  {
protected : 
    string nom;
    string adresseEmail;
    
    vector<Voyage> voyagesReserves;
    agenceVoyage& agence; 
public :
        
    Client(agenceVoyage& agence, string nom, string adresseEmail) : agence(agence), nom(nom), adresseEmail(adresseEmail) {}

    void reserverVoyage(int idVoyage);
    void annulerReservationVoyage(int idVoyage);
void saisir();
    virtual void afficherDetailsClient() {
        cout << "Nom du client : " << nom << endl;
        cout << "Adresse e-mail : " << adresseEmail << endl;
        cout << "Voyages réservés :" << endl;
        for ( auto& voyage : voyagesReserves) {
            voyage.afficher();
            cout << endl;
        }
    }

		
};
class GuideTouristique {
private:
	int id;
    string nom;
    vector<string> languesParlees;
    string experience;
	 bool disponible;
	 vector<Voyage> voyages;

public:
    GuideTouristique() {}
    GuideTouristique(int id,string nom, const vector<string>& languesParlees, string experience, bool disponible)
        : id(id),nom(nom), languesParlees(languesParlees), experience(experience), disponible(disponible) {}
	string getNom() const {
        return nom;
    }
int getId() const {
        return id;
    }
    bool estDisponible() const {
        return disponible;
    }
	void ajouterVoyage( Voyage& voyage) {
        voyages.push_back(voyage);
    }

    // Méthode pour récupérer la liste des voyages associés à ce guide
    const vector<Voyage>& getVoyages()  {
        return voyages;
    }
    // Méthode pour afficher les détails du guide
    void afficherDetailsGuide() const {
        cout << "Nom du guide : " << nom << endl;
        cout << "Langues parlées : ";
        for (const auto& langue : languesParlees) {
            cout << langue << ", ";
        }
        cout << endl;
        cout << "Expérience : " << experience << endl;
        cout << "Disponibilité : " << disponible << endl;
    }
     bool reserverGuidePourVoyage(Voyage& voyage)  {
        if (disponible) {
            disponible = false;
            cout << "Guide " << nom << " réservé pour le voyage avec identifiant " << voyage.getIdV() << "." << endl;
            return true;
        } else {
            cout << "Désolé, le guide " << nom << " n'est pas disponible pour ce voyage." << endl;
            return false;
        }
    }
};
class Forfait;
class agenceVoyage {
protected :
    vector<Voyage> voyagesDispo;
    vector<Client> clientsAgence;
    vector<GuideTouristique> guidesAgence;
    vector<Forfait> forfaits; 
public : 
        agenceVoyage() {}
const vector<GuideTouristique>& getGuidesAgence() const {
        return guidesAgence;
    }
const vector<Forfait>& getForfaits() const {
        return forfaits;
    }
    vector<GuideTouristique> getGuidesDispo() const {
       vector<GuideTouristique> availableGuides;
        // on assume tt les guides sont dispo
        availableGuides = guidesAgence;
        return availableGuides;
    }
    void afficherDetailsGuides() {
    cout << "Détails des guides touristiques :" << endl;
    for (const auto& guide : guidesAgence) {
        guide.afficherDetailsGuide();
        cout << endl;
    }
}
     vector<Voyage>& getVoyagesDispo()  {
        return voyagesDispo;
    }
    
    
    
         void ajouterVoyage(const Voyage& voyage) {
        voyagesDispo.push_back(voyage);
    }

    void ajouterClient(const Client& client) {
        clientsAgence.push_back(client);
    }
     void ajouterGuide(const GuideTouristique& guide) {
        guidesAgence.push_back(guide);
        cout << "Guide ajouté avec succès à l'agence." << endl;
    }
    
void ajouterForfait(const Forfait& forfait) {
        forfaits.push_back(forfait);
    }

    vector<Voyage> rechercherVoyageParDestination(const string& destinationName) {
    vector<Voyage> voyagesTrouves;
    for (const auto& voyage : voyagesDispo) {
        if (voyage.getDestination().getNomDestination() == destinationName) {
            voyagesTrouves.push_back(voyage);
        }
    }

    // Affichage des voyages trouvés
    if (voyagesTrouves.empty()) {
        cout << "Aucun voyage trouvé pour la destination \"" << destinationName << "\"" << endl;
    } else {
        cout << "Voyages trouvés pour la destination \"" << destinationName << "\":" << endl;
        for ( auto& voyage : voyagesTrouves) {
            voyage.afficher();
            cout << endl;
        }
    }

    return voyagesTrouves;
}



    
    void afficherDetailsReservations() {
        cout << "Voyages disponibles : " << endl;
        for ( auto& voyage : voyagesDispo) {
            voyage.afficher();
        }
        cout << endl;

        cout << "Clients de l'agence et leurs réservations : " << endl;
        for ( auto& client : clientsAgence) {
            client.afficherDetailsClient();
        }
    }

    void reserverPlace() {
        // reserver une place pour voyage
        int idVoyageAReserver;
        cout << "Entrez l'identifiant du voyage à réserver : ";
        cin >> idVoyageAReserver;
        // Call appropriate client's method
        for (auto& client : clientsAgence) {
            client.reserverVoyage(idVoyageAReserver);
        }
    }

    void annulerReservation() {
        // annuler reservation 
        int idVoyageAAnnuler;
        cout << "Entrez l'identifiant du voyage à annuler la réservation : ";
        cin >> idVoyageAAnnuler;
        for (auto& client : clientsAgence) {
            client.annulerReservationVoyage(idVoyageAAnnuler);
        }
    }
    
void afficherVoyageParID(int idVoyage)  {
    bool voyageTrouve = false;
    for ( auto& voyage : voyagesDispo) {
        if (voyage.getIdV() == idVoyage) {
            voyage.afficher();
            voyageTrouve = true;
            break;
        }
    }
    if (!voyageTrouve) {
        cout << "Aucun voyage trouvé avec l'ID spécifié." << endl;
    }
}

};

void Client::reserverVoyage(int idVoyage) {
    for (auto& voyage : agence.getVoyagesDispo()) { 
        if (voyage.getIdV() == idVoyage) {
            voyage.reserverPlace();
            voyagesReserves.push_back(voyage);
            return;
        }
    }
    cout << "Aucun voyage trouvé avec l'identifiant spécifié." << endl;
}



void Client::annulerReservationVoyage(int idVoyage) {
    for (auto i = voyagesReserves.begin(); i != voyagesReserves.end(); ++i) {
        if (i->getIdV() == idVoyage) {
            i->annulerReservation();
            voyagesReserves.erase(i);
            return;
        }
    }
    cout << "Aucun voyage trouvé avec l'identifiant spécifié." << endl;
}
void Client::saisir() {
        cout << "Saisir les informations du client :" << endl;
        cout << "Nom du client : ";
        cin >> nom;
        cout << "Adresse e-mail : ";
        cin >> adresseEmail;

        char reponse;
        do {
            int idVoyage;
            cout << "Veuillez entrer l'identifiant du voyage réservé : ";
            cin >> idVoyage;
            // Ajouter le voyage réservé à la liste des voyages réservés du client
            for (auto& voyage : agence.getVoyagesDispo()) {
                if (voyage.getIdV() == idVoyage) {
                    voyagesReserves.push_back(voyage);
                    break;
                }
            }
            cout << "Voulez-vous ajouter un autre voyage réservé ? (O/N) : ";
            cin >> reponse;
        } while (reponse == 'O' || reponse == 'o');

        // Ajouter le client à la liste des clients de l'agence
        agence.ajouterClient(*this);
    }

class Forfait : public Voyage {
protected:
    string nomForfait;
    string description;
    vector<Voyage> voyagesInclus;

public:
    Forfait() {}
    Forfait(int IdV, Destination destination, date dateDepart, date dateRetour, double Prix, int nbPlacesDisponible,
            string nomForfait, string description,vector<Voyage>& voyagesInclus) :
            Voyage(IdV, destination, dateDepart, dateRetour, Prix, nbPlacesDisponible), nomForfait(nomForfait),
            description(description),voyagesInclus(voyagesInclus) {}

    string getNomForfait() const {
        return nomForfait;
    }

    void setNomForfait(string nomForfait) {
        this->nomForfait = nomForfait;
    }

    string getDescription() const {
        return description;
    }

    void setDescription(string description) {
        this->description = description;
    }
	const vector<Voyage>& getVoyagesInclus() const {
    return voyagesInclus;
}


    void ajouterVoyageAuForfait(const Voyage& voyage) {
        voyagesInclus.push_back(voyage);
    }

virtual void afficher() const override {
        cout << "Nom du forfait : " << nomForfait << endl;
        cout << "Description : " << description << endl;
        cout << "Voyages inclus dans le forfait :" << endl;
        for ( auto& voyage : voyagesInclus) {
            voyage.afficher();
            cout << endl;
        }
    }
};

enum class modeTransport { Train, Bus, Avion };

class Transport {
protected:
    modeTransport mode;
    string compagnieTransport;
    double coutTransport;
    vector<Voyage> reservationsTransport; 

public:
    Transport(modeTransport mode, string compagnieTransport, double coutTransport)
        : mode(mode), compagnieTransport(compagnieTransport), coutTransport(coutTransport) {}

    virtual void afficherDetails() const {
		string modes[] = {"Train", "Bus", "Avion"};
        
        cout << "Mode de transport : " << modes[static_cast<int>(mode)] << endl;
		cout << "Compagnie de transport : " << compagnieTransport << endl;
        cout << "Coût du transport : " << coutTransport << " euros" << endl;
    }
    virtual void reserverTransport(const Voyage& voyage) {
        reservationsTransport.push_back(voyage); 
        cout << "Réservation du transport pour le voyage à destination de " << voyage.getDestination().getNomDestination() 
		<< " en cours pour la compagnie : " << compagnieTransport << endl;
        cout << "Coût de la réservation : " << coutTransport << " euros" << endl;
    }
};

class Train : public Transport {
public:
    Train(string compagnieTransport, double coutTransport)
        : Transport(modeTransport::Train, compagnieTransport, coutTransport) {}

    void afficherDetails() const override {
        cout << "Mode de transport : Train" << endl;
        cout << "Compagnie de train : " << compagnieTransport << endl;
        cout << "Coût du billet de train : " << coutTransport << " euros" << endl;
    }
};

class Bus : public Transport {
public:
    Bus(string compagnieTransport, double coutTransport)
        : Transport(modeTransport::Bus, compagnieTransport, coutTransport) {}

    void afficherDetails() const override {
        cout << "Mode de transport : Bus" << endl;
        cout << "Compagnie de bus : " << compagnieTransport << endl;
        cout << "Coût du billet de bus : " << coutTransport << " euros" << endl;
    }
};

class Avion : public Transport {
public:
    Avion(string compagnieTransport, double coutTransport)
        : Transport(modeTransport::Avion, compagnieTransport, coutTransport) {}

    void afficherDetails() const override {
        cout << "Mode de transport : Avion" << endl;
        cout << "Compagnie aérienne : " << compagnieTransport << endl;
        cout << "Coût du billet d'avion : " << coutTransport << " euros" << endl;
    }
};

class Excursion : public Voyage  {
private:
    string nomExcursion;
    string description;
    int duree; // en heures
    double coutSupplementaire;

public:
    Excursion(const string& nom, const string& desc, int duree, double coutSupp)
        : nomExcursion(nom), description(desc), duree(duree), coutSupplementaire(coutSupp) {}

    // ajouter une excursion à un voyage
    void ajouterExcursionAuVoyage(int idVoyage,vector<Voyage>& voyages) {
        bool voyageTrouve = false;
        for (auto& voyage : voyages) {
            if (voyage.getIdV() == idVoyage) {
                voyage.ajouterExcursion(*this);
                voyageTrouve = true;
                break;
            }
        }
        if (!voyageTrouve) {
            cout << "Aucun voyage trouvé avec l'identifiant spécifié." << std::endl;
        }
    }

    // afficher les détails de l'excursion
    virtual void afficherDetails(vector<Voyage>& voyages)  {
    	for ( auto& voyage : voyages) {
            voyage.afficher();
            cout << endl;
        }
        cout << "Nom de l'excursion : " << nomExcursion << std::endl;
        cout << "Description : " << description << std::endl;
        cout << "Durée : " << duree << " heures" << std::endl;
        cout << "Coût supplémentaire : " << coutSupplementaire << " Dirhams" << std::endl;
    }
};

int main() {
    int choix;
    agenceVoyage agence;
    Client cl(agence, "hadil", "hadil@email.com");

    do {
        cout << "\nMenu :" << endl;
        cout << "1. Gestion des voyages" << endl;
        cout << "2. Gestion des clients" << endl;
        cout << "3. Gestion des guides touristiques" << endl;
        cout << "4. Gestion des transports" << endl;
        cout << "5. Gestion des forfaits" << endl;
        cout << "6. Gestion des excursions" << endl;
        cout << "7. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                // Sous-menu Gestion des voyages
                int choixVoyage;
                cout << "\nSous-menu Gestion des voyages :" << endl;
                cout << "1. Réserver une place pour un voyage" << endl;
                cout << "2. Annuler une réservation de voyage" << endl;
                cout << "3. Ajouter un nouveau voyage" << endl;
                cout << "4. Rechercher un voyage par destination" << endl;
                cout << "5. Afficher un voyage par ID" << endl;
                cout << "6. Afficher les voyage disponibles" << endl;
                cout << "7. Retour au menu principal" << endl;
                cout << "Choix : ";
                cin >> choixVoyage;

                switch (choixVoyage) {
                    case 1: {
                        // Réserver une place pour un voyage
                        int idVoyage;
                        cout << "Entrez l'identifiant du voyage à réserver : ";
                        cin >> idVoyage;
                        cl.reserverVoyage(idVoyage);
                        agence.afficherDetailsReservations();
                        break;
                    }
                    case 2: {
                        // Annuler une réservation de voyage
                        int idVoyage;
                        cout << "Entrez l'identifiant du voyage à annuler : ";
                        cin >> idVoyage;
                        cl.annulerReservationVoyage(idVoyage);
                        agence.afficherDetailsReservations();
                        break;
                    }
                    case 3: {
                        // Ajouter un nouveau voyage
                        Voyage nouveauVoyage;
                        nouveauVoyage.saisir();
                        agence.ajouterVoyage(nouveauVoyage);
                        agence.afficherDetailsReservations();
                        break;
                    }
                    case 4: {
                        // Rechercher un voyage par destination
                        string destinationNom;
                        cout << "Entrez la destination de voyage à rechercher : ";
                        cin >> destinationNom;
                        agence.rechercherVoyageParDestination(destinationNom);
                        break;
                    }
                    case 5: {
    // Afficher un voyage par son ID
    int idVoyage;
    cout << "Entrez l'identifiant du voyage à afficher : ";
    cin >> idVoyage;
    agence.afficherVoyageParID(idVoyage);
    break;

}case 6: {
    // Afficher les détails des réservations
    agence.afficherDetailsReservations();
    break;
}case 7:
                        cout << "Retour au menu principal." << endl;
                        break;
                    default:
                        cout << "Choix invalide. Retour au menu principal." << endl;
                        break;
                }
                break;
            }
            case 2: {
                // Sous-menu Gestion des clients
                int choixClient;
                cout << "\nSous-menu Gestion des clients :" << endl;
                cout << "1. Réserver un voyage pour un client" << endl;
                cout << "2. Annuler une réservation pour un client" << endl;
                cout << "3. Ajouter un nouveau client" << endl;
                cout << "4. Afficher les détails d'un client" << endl;
                cout << "5. Retour au menu principal" << endl;
                cout << "Choix : ";
                cin >> choixClient;

                switch (choixClient) {
                    case 1: {
                        // Réserver un voyage pour un client
                        int idVoyage;
                        cout << "Entrez l'identifiant du voyage à réserver pour un client : ";
                        cin >> idVoyage;
                        cl.reserverVoyage(idVoyage);
                        cl.afficherDetailsClient();
                        agence.afficherDetailsReservations();
                        break;
                    }
                    case 2: {
                        // Annuler une réservation pour un client
                        int idVoyage;
                        cout << "Entrez l'identifiant du voyage à annuler pour un client : ";
                        cin >> idVoyage;
                        cl.annulerReservationVoyage(idVoyage);
                        cl.afficherDetailsClient();
                        agence.afficherDetailsReservations();
                        break;
                    }
                    case 3: {
                    	// Ajouter un client a un voyage
                    	cl.saisir();
						cl.afficherDetailsClient();
                        break;
                    }
                    case 4: {
                        // Afficher les détails d'un client
                        cl.afficherDetailsClient();
                        break;
                    }
                    case 5:
                        cout << "Retour au menu principal." << endl;
                        break;
                    default:
                        cout << "Choix invalide. Retour au menu principal." << endl;
                        break;
                }
                break;
            }
            case 3: {
                // Sous-menu Gestion des guides touristiques
                int choixGuide;
                cout << "\nSous-menu Gestion des guides touristiques :" << endl;
                cout << "1. Ajouter un guide touristique a l'agence" << endl;
                cout << "2. Afficher les détails des guides" << endl;
                cout << "3. Reserver un guide pour un voyage" << endl;
                cout << "4. Retour au menu principal" << endl;
                cout << "Choix : ";
                cin >> choixGuide;

                switch (choixGuide) {
                    case 1: {
                        // Ajouter un guide touristique
                        int idGuide;
                        string nomGuide;
                        vector<string> langues;
                        string experience;
                        bool disponible;
                        cout << "Entrez l'id du guide : ";
                        cin >>idGuide;
						 
                        cout << "Entrez le nom du guide : ";
                        cin >> nomGuide;
                        cout << "Entrez les langues parlées (séparées par des espaces) : ";
                        string langue;
                        while (cin >> langue) {
                            langues.push_back(langue);
                            if (cin.get() == '\n') break;
                        }
                        cout << "Entrez l'expérience du guide : ";
                        cin.ignore();
                        getline(cin, experience);
                        cout << "Entrez la disponibilite du guide :(0 dispo,1 non)) ";
                        cin >> disponible;

                        GuideTouristique guide(idGuide,nomGuide, langues, experience,disponible);
                        agence.ajouterGuide(guide);
                        
                        break;
                    }
                    
                    case 2: {
    // Afficher les détails des guides
    agence.afficherDetailsGuides();
    break;
}

                    case 3: {
    // Reserver guidepour voyage
    int idVoyage;
    cout << "Entrez l'identifiant du voyage pour lequel vous souhaitez réserver un guide : ";
    cin >> idVoyage;

    // 
    Voyage* voyage = nullptr;
    for (auto& v : agence.getVoyagesDispo()) {
        if (v.getIdV() == idVoyage) {
            voyage = &v;
            break;
        }
    }

    if (voyage) {
        cout << "Liste des guides disponibles :" << endl;
        
        int guideId;
        cout << "Entrez l'id du guide que vous souhaitez réserver : ";
        cin >> guideId;

        GuideTouristique* guide = nullptr;
        for (auto& g : agence.getGuidesDispo()) {
            if (g.getId() == guideId) {
                guide = &g;
                break;
            }
        }

        if (guide) {
            voyage->reserverGuide(guide);
            cout << "Guide réservé avec succès pour le voyage." << endl;
        } else {
            cout << "Guide non trouvé." << endl;
        }
    } else {
        cout << "Voyage non trouvé." << endl;
    }

    break;
}
case 4:
                        cout << "Retour au menu principal." << endl;
                        break;
                    default:
                        cout << "Choix invalide. Retour au menu principal." << endl;
                        break;
                }
                break;
            }
            case 4: {
                // Sous-menu Gestion des transports
                int choixTransport;
                cout << "\nSous-menu Gestion des transports :" << endl;
                cout << "1. Réserver un transport pour un voyage" << endl;
                cout << "2. Retour au menu principal." << endl;
                cout << "Choix : ";
                cin >> choixTransport;

                switch (choixTransport) {
                    case 1: {
    // Réserver un transport pour un voyage
    int idVoyage;
    cout << "Entrez l'identifiant du voyage : ";
    cin >> idVoyage;

    // Recherche du voyage dans la liste des voyages disponibles
    Voyage* voyage = nullptr;
    for (auto& v : agence.getVoyagesDispo()) {
        if (v.getIdV() == idVoyage) {
            voyage = &v;
            break;
        }
    }

    if (voyage) {
        
        double coutTransport;

        cout << "Entrez le mode de transport (0: Train, 1: Bus, 2: Avion) : ";
        int modeInt;
        cin >> modeInt;
                modeTransport mode;

        mode = static_cast<modeTransport>(modeInt);

        cout << "Entrez la compagnie de transport : ";
        cin.ignore();
                string compagnie;

        getline(cin, compagnie);

        cout << "Entrez le coût du transport : ";

        cin >> coutTransport;

        // Réserver le transport pour le voyage
        cout << "Transport réservé pour le voyage." << endl;
Transport transport(mode, compagnie, coutTransport); 
transport.reserverTransport(*voyage); 
cout << "Transport réservé pour le voyage." << endl;

        transport.reserverTransport(*voyage);
        transport.afficherDetails();
    } else {
        cout << "Voyage non trouvé." << endl;
    }
    break;
}




                    case 2:
                        cout << "Retour au menu principal." << endl;
                        break;
                    default:
                        cout << "Choix invalide. Retour au menu principal." << endl;
                        break;
                }
                break;
            }
       case 5: {
    // Sous-menu Gestion des forfaits
    int choixForfait;
    cout << "\nSous-menu Gestion des forfaits :" << endl;
    cout << "1. Ajouter un voyage au forfait" << endl;
    cout << "2. Afficher les détails des forfaits" << endl;
    cout << "3. Retour au menu principal." << endl;
    cout << "Choix : ";
    cin >> choixForfait;

    switch (choixForfait) {
        case 1: {
    // Ajouter un nouveau forfait
    string nomForfait, descriptionForfait;
    // Saisie des informations du forfait
    cout << "Nom du forfait : ";
    cin >> nomForfait;
    cout << "Description du forfait : ";
    cin >> descriptionForfait;
    // Création du forfait avec les informations saisies
    Forfait nouveauForfait;
    nouveauForfait.setNomForfait(nomForfait);
    nouveauForfait.setDescription(descriptionForfait);

    // Ajout des voyages au forfait
    int nbVoyages;
    cout << "Combien de voyages voulez-vous ajouter à ce forfait ? ";
    cin >> nbVoyages;
    for (int i = 0; i < nbVoyages; ++i) {
        int idVoyage;
        cout << "Entrez l'identifiant du voyage à ajouter au forfait : ";
        cin >> idVoyage;

        // Recherche du voyage dans la liste des voyages disponibles
        Voyage* voyage = nullptr;
        for (auto& v : agence.getVoyagesDispo()) {
            if (v.getIdV() == idVoyage) {
                voyage = &v;
                break;
            }
        }

        if (voyage) {
            // Ajout du voyage au forfait
            nouveauForfait.ajouterVoyageAuForfait(*voyage);
            cout << "Voyage ajouté au forfait." << endl;

        } else {
            cout << "Voyage non trouvé." << endl;
        }
    }

    // Ajouter le forfait au vecteur des forfaits de la classe agence
    agence.ajouterForfait(nouveauForfait);

    break;
}

    case 2: {
    // Demander le nom du forfait à afficher
    string nomForfait;
    cout << "Entrez le nom du forfait que vous souhaitez afficher avec ses voyages associés : ";
    cin >> nomForfait;

    // Recherche du forfait dans la liste des forfaits disponibles
    bool forfaitTrouve = false;
    for (const auto& forfait : agence.getForfaits()) {
        if (forfait.getNomForfait() == nomForfait) {
            // Afficher les détails du forfait et ses voyages associés
            cout << "Détails du forfait '" << nomForfait << "' :" << endl;
            cout << "Description du forfait : " << forfait.getDescription() << endl;
            cout << "Voyages inclus dans ce forfait :" << endl;
            for (const auto& voyage : forfait.getVoyagesInclus()) {
                voyage.afficher();
            }
            cout << endl;
            forfaitTrouve = true;
            break;
        }
    }

    if (!forfaitTrouve) {
        cout << "Le forfait '" << nomForfait << "' n'a pas été trouvé." << endl;
    }

    break;
}

        case 3: {
            cout << "Retour au menu principal." << endl;
            break;
        }
        default: {
            cout << "Choix invalide. Retour au menu principal." << endl;
            break;
        }
    }
    break;
}


case 6: {
    // Sous-menu Gestion des excursions
    int choixExcursion;
    cout << "\nSous-menu Gestion des excursions :" << endl;
    cout << "1. Ajouter une nouvelle excursion a un voyage" << endl;
    cout << "2. Afficher les détails des excursions" << endl;
    cout << "3. Retour au menu principal." << endl;
    cout << "Choix : ";
    cin >> choixExcursion;

     switch (choixExcursion) {
        case 1: {
            // Ajouter une nouvelle excursion à un voyage
            int idVoyage;
            cout << "Entrez l'identifiant du voyage auquel ajouter l'excursion : ";
            cin >> idVoyage;

            // Recherche du voyage dans la liste des voyages disponibles
            for (auto& voyage : agence.getVoyagesDispo()) {
                if (voyage.getIdV() == idVoyage) {
                    string nomExcursion, descriptionExcursion;
                    int dureeExcursion;
                    double coutSupplementaireExcursion;

                    cout << "Entrez le nom de l'excursion : ";
                    cin >> nomExcursion;
                    cout << "Entrez la description de l'excursion : ";
                    cin >> descriptionExcursion;
                    cout << "Entrez la durée de l'excursion (en heures) : ";
                    cin >> dureeExcursion;
                    cout << "Entrez le coût supplémentaire de l'excursion : ";
                    cin >> coutSupplementaireExcursion;

                    // Créez une nouvelle instance d'Excursion avec les détails saisis
                    Excursion nouvelleExcursion(nomExcursion, descriptionExcursion, dureeExcursion, coutSupplementaireExcursion);

                    // Ajoutez l'excursion au voyage
                    nouvelleExcursion.ajouterExcursionAuVoyage(idVoyage, agence.getVoyagesDispo());
                    break;
                }
            }
            break;
        }
        case 2: {
    // Afficher les détails des excursions
    int idVoyage;
    cout << "Entrez l'identifiant du voyage dont vous souhaitez afficher les excursions : ";
    cin >> idVoyage;

    // Recherche du voyage dans la liste des voyages disponibles
    for (auto& voyage : agence.getVoyagesDispo()) {
        if (voyage.getIdV() == idVoyage) {
            cout << "Excursions ajoutées au voyage :" << endl;
            for (auto& excursion : voyage.getExcursions()) {
                excursion.afficherDetails(agence.getVoyagesDispo());
            }
            break;
        }
    }
    break;
}

        case 3: {
            cout << "Retour au menu principal." << endl;
            break;
        }
        default:
            cout << "Choix invalide. Retour au menu principal." << endl;
            break;
    }
    break;
}

            case 7:
                cout << "Programme terminé." << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
                break;
        }
    } while (choix != 7);

    return 0;
}
