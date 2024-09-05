#ifndef MULTIMEDIA_H_
#define MULTIMEDIA_H_

#include <string>
#include <iostream>


/**
 * @class Multimedia
 * @brief Represents a multimedia object with a name and a file name.
 *
 * This class provides basic functionality for multimedia objects, including
 * getters and setters for the name and file name, as well as virtual functions
 * for printing and playing.
 */
class Multimedia {
protected:
	std::string name {};
	std::string path {};

public:
    /**
     * @brief Default constructor for Multimedia class.
     */
	Multimedia();

   /**
	 * @brief Parameterized constructor for Multimedia class.
	 * @param name The name of the multimedia object.
	 * @param path The file name of the multimedia object.
	 */
	Multimedia(const std::string &, const std::string &);

   /**
	 * @brief Sets the name of the multimedia object.
	 * @param name The new name for the multimedia object.
	 */
	void set_name(const std::string&);

    /**
     * @brief Sets the file name of the multimedia object.
     * @param path The new file name for the multimedia object.
     */
	void set_path(const std::string&);

    /**
     * @brief Gets the name of the multimedia object.
     * @return A constant reference to the name of the multimedia object.
     */
	const std::string& get_name() const;

   /**
	 * @brief Gets the file name of the multimedia object.
	 * @return A constant reference to the file name of the multimedia object.
	 */
	const std::string& get_path() const;

   /**
	 * @brief Virtual function to print information about the multimedia object.
	 * @param output The output stream to write the information to.
	 * @return A reference to the output stream.
	 */
	virtual std::ostream& afficher(std::ostream &) const;

    /**
     * @brief Pure virtual function to play the multimedia object.
     *
     * Subclasses must implement this function to define the specific
     * behavior of playing the multimedia object.
     */
	virtual void play() const = 0 ;

    /**
     * @brief Destructor for Multimedia class.
     */
	virtual ~Multimedia();
};

#endif
