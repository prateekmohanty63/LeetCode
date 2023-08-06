#include<iostream>
#include<vector>
using namespace std;

// 4 pillars of oops

// 1. Inheritance
// 2. Encapsulation
// 3. Polymorphism 
// 4. Data abstraction


// Designing a spofity system

class song
{
   private:
   int songId;
   int albumId;
   string songName;
   int duration;
   int artistId;

   public: 
   // default constructor

   song(){};

   song(int songId,int albumId,string songName,int duration)
   {
       this->songId=songId;
       this->albumId=albumId;
       this->songName=songName;
       this->duration=duration;
    //   this->artistId=Obj.getUserId();
      
   }

   // getter and setter functions
   string getSongName()
   {
    return songName;
   }

   int getDuration()
   {
      return duration;
   }
};


class User
{
    private:
    int userId;
    static int nextId;
    string email;
    bool isArtist=false;

   public:
    User(){};

    void setEmail(string email)
    {
        this->email=email;
    }

    string getEmail()
    {
        return email;
    }

    User(string email)
    {
        userId=nextId;
        nextId++;
        this->email=email;

    }

    int getUserId(){
        return userId;
    }

    void setIsArtist(bool isArtist)
    {
        this->isArtist=isArtist;
    }

    virtual int noSongsComposed()
    {
        return 0;
    }

};

int User::nextId=1;



class artist:public User
{
     // setIsArtist(true);
     vector<song>songsComposed;
     static int nextId;
     int artistId;

     public: 

     artist(){};

     artist(string email)
     {
          setEmail(email);
          setIsArtist(true);
          artistId=nextId;
          nextId++;
     }

     int getArtistId()
     {
        return getUserId();
     }

     void addSong(song obj)
     {
        songsComposed.push_back(obj);
     }

     int noSongsComposed()
     {
         return songsComposed.size();
     }

     void displaySongList()
     {
        for(auto song:songsComposed)
        {
            cout<<"songName: "<<song.getSongName()<<" by "<<this->getEmail()<<endl;
        }
     }
};

int artist::nextId=1;



class bhajan:public song
{
    string god;

    bhajan(int songId,int albumId,string songName,int duration,string god)
    {
        song(songId,albumId,songName,duration);
        this->god=god;
    }
};



class album
{

    vector<song>list;
    int albumId;
    static int nextId;
    artist singer;
   
   public:
    

    album(artist obj)
    {
        albumId=nextId;
        singer=obj;
        nextId++;
    }

    void getSongs()
    {
        for(auto it:list)cout<<it.getSongName()<<endl;
    }

    void addSong(song obj)
    {
        list.push_back(obj);
    }

    int getNoOfSongs()
    {
        return list.size();
    }
};


int album::nextId=1;

int main()
{
    // creating a normal user 
    User *user1=new User("abc@gmail.com");
    cout<<user1->getUserId()<<endl;

    User *user2=new User("abc1@gmail.com");
    cout<<user2->getUserId()<<endl;


    // creating a artist 

    artist *artist1=new artist("artist1@gmail.com");
    //cout<<artist1->getEmail()<<endl;

    // create a song 
    song song1(1,1,"hello",3);
    artist1->addSong(song1);

    artist1->displaySongList();

    //  concept of polymorphism 

    // run time polymorphism 
    User* user3=artist1;
    cout<<user3->noSongsComposed();
    return 0;
}