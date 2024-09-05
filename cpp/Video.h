#ifndef VIDEO_H_
#define VIDEO_H_

#include "Multimedia.h"

/**
 * @class Video
 * @brief Represents a video with additional information such as duration.
 *
 * This class extends the Multimedia class and adds duration information to
 * represent a video's length.
 */

class Video: public Multimedia {
protected:
	int duree{};

public:
    /**
     * @brief Default constructor for Video class.
     */
	Video():Multimedia(){};

    /**
     * @brief Parameterized constructor for Video class.
     * @param name The name of the video.
     * @param path The file name of the video.
     * @param duree The duration of the video in minutes.
     */
	Video(const std::string& name, const std::string& path, int duree)
	:Multimedia(name ,path) // @suppress("Ambiguous problem")
	{
		this->duree = duree;
	}

   /**
	 * @brief Sets the duration of the video.
	 * @param duree The new duration for the video in minutes.
	 */
	void set_duree(float duree){this->duree = duree;}

    /**
     * @brief Gets the duration of the video.
     * @return The duration of the video in minutes.
     */
	unsigned int get_duree() const {return this->duree;}

    /**
     * @brief Overrides the print function from the Multimedia class to include
     * duration information.
     * @param output The output stream to write the information to.
     * @return A reference to the output stream.
     */
	virtual std::ostream& afficher(std::ostream& f) const override {
		Multimedia::afficher(f)<<"Duree: "<<this->duree;
		return f;
	}

    /**
     * @brief Overrides the play function from the Multimedia class to open the
     * video using an external program.
     */
	void play() const override {
		std::string commande ="mpv "+this->get_path()+" &";
		system(commande.c_str()); //pour windows ?
	}

    /**
     * @brief Destructor for Video class.
     */
	virtual ~Video(){};
};

#endif
