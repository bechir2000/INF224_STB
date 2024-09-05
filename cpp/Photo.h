
#ifndef PHOTO_H_
#define PHOTO_H_

#include "Multimedia.h"

/**
 * @class Photo
 * @brief Represents a photo with additional information such as latitude and longitude.
 *
 * This class extends the Multimedia class and adds latitude and longitude
 * information to represent a photo's location.
 */
class Photo: public Multimedia{
protected:
	float longitude{};
	float latitude{};

public:
    /**
     * @brief Default constructor for Photo class.
     */
	Photo():Multimedia(){};

    /**
     * @brief Parameterized constructor for Photo class.
     * @param name The name of the photo.
     * @param path The file name of the photo.
     * @param lat The latitude information of the photo.
     * @param lon The longitude information of the photo.
     */
	Photo(const std::string& name, const std::string& path, float lat, float lon)
	:Multimedia(name ,path)
	{
		this->latitude = lat;
		this->longitude = lon;
	}

    /**
     * @brief Sets the latitude information of the photo.
     * @param latitude The new latitude for the photo.
     */
	void set_latitude(float lat){this->latitude = lat;}

    /**
     * @brief Sets the longitude information of the photo.
     * @param longitude The new longitude for the photo.
     */
	void set_longitude(float lon){this->longitude = lon;}


    /**
     * @brief Gets the longitude information of the photo.
     * @return The longitude of the photo.
     */
	float get_longitude() const {return this->longitude;}

    /**
     * @brief Gets the latitude information of the photo.
     * @return The latitude of the photo.
     */
	float get_latitude() const {return this->latitude;}

   /**
	 * @brief Overrides the print function from the Multimedia class to include
	 * latitude and longitude information.
	 * @param output The output stream to write the information to.
	 * @return A reference to the output stream.
	 */
	virtual std::ostream& afficher(std::ostream& f) const override {
		Multimedia::afficher(f)<<"Latitude: "<<this->latitude<<"----Longitude: "<<this->longitude<<"\n";
		return f;
	}

   /**
	 * @brief Overrides the play function from the Multimedia class to open the
	 * photo using an external program.
	 */
	void play() const override {
		std::string commande ="mpv "+this->get_path()+" &";
		system(commande.c_str()); //pour windows ?
	}

    /**
	 * @brief Destructor for Photo class.
	 */
	~Photo(){};
};

#endif /* PHOTO_H_ */
