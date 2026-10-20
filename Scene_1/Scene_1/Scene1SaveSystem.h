#pragma once
class MuiroDetails;
class Scene1SaveSystem {
public:
	void saveHealth(const MuiroDetails& muiro);
	bool loadHealth(MuiroDetails& muiro);
};