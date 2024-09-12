#include "Header.h"

namespace zxc
{
	int runtimes()
	{
		std::ifstream in("runtimes.txt");
		std::ofstream out("runtimes.txt", std::ios::app);
		std::string len;
		out << '1';
		in >> len;

		return len.length()+1;
	}

	void dateplus(int runtimes)
	{
		std::ofstream out("output.txt", std::ios::app);

		time_t now = time(NULL);
		tm t = *localtime(&now);

		out << runtimes << "_" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << "-" << t.tm_hour << "-" << t.tm_min << "-" << t.tm_sec << std::endl;
	}
	

}
