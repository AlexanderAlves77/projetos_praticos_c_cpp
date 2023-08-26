#pragma once
class OWindow
{
private:
	void* m_handle = nullptr;

public:
	OWindow();
	~OWindow();

	void onDestroy();
	bool isClosed();
};

