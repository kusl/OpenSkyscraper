#pragma once
#include <Rocket/Core/ElementDocument.h>
#include <Rocket/Core/Element.h>
#include <string>
#include "GameObject.h"

namespace OT {
	
	class TimeWindow : public GameObject
	{
	public:
		TimeWindow(Game * game) : GameObject(game) {
			window        = NULL;
			ratingDiv     = NULL;
			fundsDiv      = NULL;
			populationDiv = NULL;
			messageTimer  = 0;
		}
		~TimeWindow() { close(); }
		
		void close();
		void reload();
		
		Rocket::Core::ElementDocument * window;
		Rocket::Core::Element * ratingDiv;
		Rocket::Core::Element * fundsDiv;
		Rocket::Core::Element * populationDiv;
		
		void updateTime();
		void updateRating();
		void updateFunds();
		void updateTooltip();
		
		double messageTimer;
		std::string message;
		void showMessage(std::string msg);
		
		void advance(double dt);
		
		static std::string formatMoney(int amount);
	};
}
