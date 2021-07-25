#include "Process.h"
#include "Utils.h"
using namespace Utils;

/* 
* @brief pop
* 
*/
void Process::pop() {
	client->pop();
	time_arrival->pop();
	time_wait->pop();
	time_notworking->pop();
	time_service->pop();
	time_out->pop();
	time_between->pop();
}

/* 
* @brief calculate_all
* @param int lenght
*/
void Process::calculate_all(int lenght) {
	int time_before = 0;
	for(int i = 0;  i< lenght; i++)
	{
		calculate_client();
		calculate_time_arrival();
		calculate_time_wait();
		calculate_time_notworking();
		calculate_time_service();
		calculate_time_out();
		calculate_time_between(time_before);
		time_before = time_arrival->get_rear();
	}
}

/* 
* @brief calculate_client
* 
*/
void Process::calculate_client() {
	size++;
	client->push(size);
}

/* 
* @brief calculate_time_arrival
* 
*/
void Process::calculate_time_arrival() {
	if (size == 1) {
		time_arrival->push(Utils::Validation::random_numbers(1, 25));
	}
	else {
		int calculate = time_arrival->get_rear() + Utils::Validation::random_numbers(1, 25);
		time_arrival->push(calculate);
	}
}

/* 
* @brief calculate_time_wait
* 
*/
void Process::calculate_time_wait() {
	if (size == 1) {
		time_wait->push(0);
	}
	else {
		int calculate = Utils::Math::max<int>(time_out->get_rear(), time_arrival->get_rear()) - time_arrival->get_rear();
		time_wait->push(calculate);
	}
}

/* 
* @brief calculate_time_notworking
* 
*/
void Process::calculate_time_notworking() {
	if (size == 1) {
		time_notworking->push(0);
	}
	else {
		int calculate = Utils::Math::max<int>(time_arrival->get_rear(), time_out->get_rear()) - time_out->get_rear();
		time_notworking->push(calculate);
	}
}

/* 
* @brief calculate_time_service()
* 
*/
void Process::calculate_time_service() {
	time_service->push(Utils::Validation::random_numbers(1, 16));
}
/* 
* @brief calculate_time_out()
* 
*/
void Process::calculate_time_out() {
	int calculate = time_arrival->get_rear() + time_wait->get_rear() + time_service->get_rear();
	time_out->push(calculate);
}
/* 
* @brief calculate_time_between
* @param int arrival_bf
*/
void Process::calculate_time_between(int arrival_bf) {
	if (size == 0) {
		time_between->push(time_arrival->get_rear());
	}
	else {
		int calculate = time_arrival->get_rear() - arrival_bf;
		time_between->push(calculate);
	}
}
/* 
* @brief print_total()
* 
*/

void Process::print_total() {
	auto time_calculate = [](int time, int limit) {
		float avarage = time / (float)limit;
		if (avarage >= 60) {

			printf("%.2f horas. \n", avarage/60);
		}
		else {
			printf("%.2f minutos. \n", avarage);
		}
	};

	//std::cout << "Size: " << size << std::endl;
	float _avarage_wait = 0, avarage_notworking = 0, avarage_service = 0, avarage_between = 0;
	int avarage_wait = 0;
	time_wait->calculate([&_avarage_wait](int data, int i) {
		_avarage_wait += data;
	});
	//std::cout << "TIEMPO DE ESPERA PROMEDIO: " << _avarage_wait / size <<" minutos." << std::endl;
	std::cout << "TIEMPO DE ESPERA PROMEDIO: "; time_calculate(_avarage_wait, size);

	//Si el tiempo pasa de 60, hacer que se ponga en horas y minutos uwuwuwuwuwu RECUERDA HACER ESTOOOO!!!

	time_notworking->calculate([&avarage_notworking](int data, int i) {
		avarage_notworking += data;
	}); 
	//std::cout << "TIEMPO NO TRABAJA EL CAJERO: " << avarage_notworking / size << " minutos." << std::endl;
	std::cout << "TIEMPO NO TRABAJA EL CAJERO: "; time_calculate(avarage_notworking, size);

	time_wait->calculate([&avarage_wait](int data, int i) {
		if (data > 0) {
			avarage_wait++;
		}
	});
	std::cout << "NUMERO PROMEDIO DE CLIENTES EN COLA: " << avarage_wait << std::endl;

	time_service->calculate([&avarage_service](int data, int i) {
		avarage_service += data;
	});
	std::cout << "TIEMPO PROMEDIO DE SERVICIO: " << avarage_service / size << std::endl;

	time_between->calculate([&avarage_between](int data, int i) {
		avarage_between += data;
	});
	std::cout << "PROMEDIO DE TIEMPO ENTRE LLEGADAS: " << avarage_between / size << std::endl;
}

/* 
* @brief print_table
* @param int num
*/

void Process::print_table(int num) {
	int* _client = new int[num];
	int* _time_arrival = new int[num];
	int* _time_wait = new int[num];
	int* _time_notworking = new int[num];
	int* _time_service = new int[num];
	int* _time_out = new int[num];
	int*_time_between = new int[num];

	auto assignment = [&]() {
		client->calculate([=, &_client](int data, int i = 0) {
			*(_client + i) = data;
		});

		time_arrival->calculate([=](int data, int i) {
			*(_time_arrival + i) = data;
		});

		time_wait->calculate([=](int data, int i) {
			*(_time_wait + i) = data;
		});

		time_notworking->calculate([=](int data, int i) {
			*(_time_notworking + i) = data;
		});

		time_service->calculate([=](int data, int i) {
			*(_time_service + i) = data;
		});

		time_out->calculate([=](int data, int i) {
			*(_time_out + i) = data;
		});

		time_between->calculate([=](int data, int i) {
			*(_time_between + i) = data;
		});
	};

	auto print_tbl = [=]() {
		printf("+-----+---------------+--------------+------------------+----------------+--------------+----------------------+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",
		-5, " No.", -10," Tiempo Llegada", -10, " Tiempo Espera", -10, " Tiempo no Trabajo", -10," Tiempo Servicio", -10, " Tiempo Salida",-10, " Tiempo entre Llegadas");
		//std::cout << "Cliente\tTiempo de llegada\tTiempo de espera\tTiempo no trabaja el cajero\tTiempo de servicio\tTiempo de salida\tTiempo entre llegadas" << std::endl;
			printf("|-----+---------------+--------------+------------------+----------------+--------------+----------------------|\n");
		for (int i = 0; i < num; i++) {
			printf("|%*d|%*d|%*d|%*d|%*d|%*d|%*d|\n",
				-5, *(_client + i), -15, *(_time_arrival + i), -14, *(_time_wait + i),-18, *(_time_notworking + i), -16, *(_time_service + i), -14, *(_time_out + i), -22, *(_time_between + i));
			printf("|-----+---------------+--------------+------------------+----------------+--------------+----------------------|\n");
			/*	std::cout << *(_client + i) <<"\t\t" << *(_time_arrival + i)<<"\t\t"
				<< *(_time_wait + i) <<"\t\t\t"<< *(_time_notworking + i)<<"\t\t\t"
				<<*(_time_service + i)<< "\t\t" << *(_time_out + i) <<"\t\t"
				<< *(_time_between + i) << std::endl;*/
		}
	};

	assignment();
	print_tbl();
}


Queues<int>* Process::get_time_client() {
	return client;
}


Queues<int>* Process::get_time_arrival() {
	return time_arrival;
}


Queues<int>* Process::get_time_wait() {
	return time_wait;
}


Queues<int>* Process::get_time_notworking() {
	return time_notworking;
}


Queues<int>* Process::get_time_service() {
	return time_service;
}


Queues<int>* Process::get_time_out() {
	return time_out;
}


Queues<int>* Process::get_time_between() {
	return time_between;
}
