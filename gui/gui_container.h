/*
 * Copyright (c) 1997 - 2001 Hansj�rg Malthaner
 *
 * This file is part of the Simutrans project under the artistic licence.
 * (see licence.txt)
 */

#ifndef gui_container_h
#define gui_container_h


#include "../simdebug.h"
#include "../simevent.h"
#include "../tpl/slist_tpl.h"
#include "components/gui_komponente.h"

/**
 * Ein Beh�lter f�r andere gui_komponenten. Ist selbst eine
 * gui_komponente, kann also geschachtelt werden.
 *
 * @author Hj. Malthaner
 * @date 03-Mar-01
 */
class gui_container_t : public gui_komponente_t
{
private:
	slist_tpl <gui_komponente_t *> komponenten;

	// holds the GUI Komponent that has the focus in this window
	gui_komponente_t *komp_focus;

	bool list_dirty:1;

	/// true, while infowin_event is processed
	bool inside_infowin_event:1;
public:
	gui_container_t();

	// needed for WIN_OPEN events
	void clear_dirty() {list_dirty=false;}

	/**
	* F�gt eine Komponente zum Container hinzu.
	* @author Hj. Malthaner
	*/
	void add_komponente(gui_komponente_t *komp);

	/**
	* Entfernt eine Komponente aus dem Container.
	* @author Hj. Malthaner
	*/
	void remove_komponente(gui_komponente_t *komp);

	bool infowin_event(event_t const*) OVERRIDE;

	/**
	* Zeichnet die Komponente
	* @author Hj. Malthaner
	*/
	virtual void zeichnen(koord offset);

	/**
	* Entfernt alle Komponenten aus dem Container.
	* @author Markus Weber
	*/
	void remove_all();

	/**
	 * Returns true if any child component is focusable
	 * @author Knightly
	 */
	virtual bool is_focusable();

	/**
	 * Activates this element.
	 *
	 * @warning Calling this method from anything called from
	 * gui_container_t::infowin_event (e.g. in action_triggered)
	 * will have NO effect.
	 */
	void set_focus( gui_komponente_t *komp_focus );

	/**
	 * returns element that has the focus
	 * that is: go down the hierarchy as much as possible
	 */
	virtual gui_komponente_t *get_focus();

	/**
	 * Get the relative position of the focused component.
	 * Used for auto-scrolling inside a scroll pane.
	 * @author Knightly
	 */
	virtual koord get_focus_pos() { return komp_focus ? pos+komp_focus->get_focus_pos() : koord::invalid; }
};

#endif
