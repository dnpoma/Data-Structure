//#include "File.h"
//#include <iomanip>
//
//void File::add_word(int key, Node* tmp) {
//	//std::ifstream file("words.json");
//	//json js;
//	//Node tmp;
//	//file >> js;
//	//if (key == js[key]["id"].get<int>()) {
//	//	write_js(js, tmp);
//	//}
//	json js;
//	write_js(js, tmp);
//	std::ofstream file("words.json");
//	file << std::setw(4) << js << std::endl;
//
//}
//void File::write_js(json& js, Node* data) {
//	int key = data->get_height();
//	js[key]["id"] = data->get_height();
//	js[key]["english"] = data->get_english();
//	js[key]["spanish"] = data->get_spain();
//}