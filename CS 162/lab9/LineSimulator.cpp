/*********************************************************************
** Program Filename: LineSimulator.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             11/20/2015
** Description:      A class to simulate simplistic queue models
** Input:            Requres a label, number of lines, number of serve_customers
**                   and number of ticks to generate new customers for
** Output:           Calling run_simulation() will run the simulation
**                   based on the input values.
** Note:             Does not "reset" itself; instantiate a new
**                   object to run multiple simulations
********************************************************************/
#include "LineSimulator.hpp"

/*********************************************************************
 ** Function:         LineSimulator()
 ** Description:      Constructor. Sets up the simulator.
 ** Parameters:       std::string label, int num_lines, int num_servers,
 **                   int new_customers_ticks.
 ** Pre-Conditions:   None
 ** Post-Conditions:  LineSimulator will be availble for use.
 ********************************************************************/
LineSimulator::LineSimulator(const std::string label, const int num_lines, const int num_servers, const int new_customers_ticks)
{
  this->label = label;
  this->num_lines = num_lines;
  this->num_servers = num_servers;
  this->time_tick = 0;
  this->new_customers_ticks = new_customers_ticks;
  this->total_wait_time = 0;
  this->total_customers = 0;

  for (int i = 0; i < num_lines; i++)
  {
    std::queue<Person> new_queue;
    cust_queue.push_back(new_queue);
  }
}


/*********************************************************************
 ** Function:         run_simulation()
 ** Description:      Runs a simulation by iterating at list new_customers_ticks
 **                   times until there are no customers in the queues
 ** Parameters:       None
 ** Pre-Conditions:   A fresh instantiation of LineSimulator must exist
 ** Post-Conditions:  Will run the simulations and print the results
 ********************************************************************/
void LineSimulator::run_simulation()
{
  // Loop continues if customers are still being generated or if some have not been served
  do
  {
    tick();
  } while (time_tick <= new_customers_ticks || count_customers() > 0);
  print_status();

}


/*********************************************************************
** Function:         tick()
** Description:      Calls all necessary subroutines to process a tick
** Parameters:       None
** Pre-Conditions:   Should be called by main loop (run_simulation())
** Post-Conditions:  Print info @ various stages; advances time_tick
********************************************************************/
void LineSimulator::tick()
{
  std::cout << "***Customers in line before Tick" << time_tick << ": " << count_customers() << "\n";
  populate_line();
  std::cout << "***Customers in line with new customers added: " << count_customers() << "\n";
  serve_customers();
  std::cout << "***Customers in line at after Tick " << time_tick << ": " << count_customers() << "\n";
  time_tick++;
}


/*********************************************************************
** Function:         populate_line()
** Description:      Adds customers to the queue
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  The queues will have any additional customers
**                   added to their structures
********************************************************************/
void LineSimulator::populate_line()
{
  int quantity = generate_customers();

  std::cout << "**Adding " << quantity << " new customers to queue(s).\n";

  for (int i = 0; i < quantity; i ++)
  {
    int queue_index = (i % num_lines);
    total_wait_time += calculate_wait_time(queue_index);
    total_customers++;
    Person next_cust(total_customers);
    cust_queue[queue_index].push(next_cust);
    std::cout << "Customer " << next_cust.get_id() << " added to Line[" << queue_index << "]\n";
  }
}


/*********************************************************************
** Function:         calculate_wait_time()
** Description:      Determines the wait time an individual customer
**                   will have based on how many people are in front
**                   of them in queue. We can calculate this because
**                   we know every server can process a customer in 1
**                   "tick" (time unit)
** Parameters:       The index of the queue they are going into
** Pre-Conditions:   Queues must exist to be pushed to
** Post-Conditions:  Returns the wait time as an integer
********************************************************************/
int LineSimulator::calculate_wait_time(const int index) const
{
  double result = std::floor(static_cast<double>(cust_queue[index].size()) * static_cast<double>(num_lines) / static_cast<double>(num_servers));
  int int_result = static_cast<int>(result);
  return result;
}


/*********************************************************************
** Function:         count_customers()
** Description:      Counts all of the customers in all of the queues
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns the number of customers in all of the queues
********************************************************************/
int LineSimulator::count_customers() const
{
  int customers = 0;
  for (int i = 0; i < num_lines; i++)
  {
    customers += cust_queue[i].size();
  }
  return customers;
}


/*********************************************************************
** Function:         serve_customers()
** Description:      Pulls customers out of each line. If a queue has
**                   no customers, then moves forward one queue (But
**                   does not increment the current server "pulling")
** Parameters:       None
** Pre-Conditions:   Should not be called unless there are customers
** Post-Conditions:  Each queue will have num_servers/num_lines less
**                   People in them
********************************************************************/
void LineSimulator::serve_customers()
{
  int queue_index = 0;
  for (int i = 0; (i < num_servers) && (count_customers() > 0); i ++)
  {
    // only remove people if queue not empty; move through queues until find one with people
    while (cust_queue[queue_index].size() == 0)
      queue_index = ((queue_index + 1) % num_lines);

    Person customer = cust_queue[queue_index].front();
    cust_queue[queue_index].pop();
    std::cout << "Customer " << customer.get_id() << " removed from Line[" << queue_index << "]\n";
    queue_index = ((queue_index + 1) % num_lines);
  }
}


/*********************************************************************
** Function:         generate_customers()
** Description:      Algorithm to calculate number of customers to put
**                   into the quueues each tick
** Parameters:       None
** Pre-Conditions:   Needs to work on a fully initialized LineSimulator
** Post-Conditions:  Returns a (somewhat) bell shaped distribution of
**                   integers over the time units.
********************************************************************/
int LineSimulator::generate_customers() const
{
  // Only add more customers for new_customers_ticks iterations of tick() (the "business hours")
  if (time_tick < new_customers_ticks)
  {
    int random = std::rand() % 3;
    // first half the number added grows as T*n + Rand, where T is the unit of time, n is number of servers, and Rand is a random variance of 0 to 2
    int num_customers = (time_tick < (new_customers_ticks / 2)) ? ((time_tick * num_servers) + random) : (((new_customers_ticks - (time_tick + 1)) * num_servers) + random);
    return num_customers;
  }
  // There will be additional ticks after the customers come in that we need to clear out... this handles that
  else
    return 0;
}


/*********************************************************************
** Function:         print_status()
** Description:      Reports information about the simulation run
** Parameters:       None
** Pre-Conditions:   Should be called after all iterations done
** Post-Conditions:  Prints total wait time, customers, and average
**                   wait time.
********************************************************************/
void LineSimulator::print_status() const
{
  std::cout << "Simulation: " << label << "\n";
  std::cout << "Number of Lines (Queues) = " << num_lines << "\n";
  std::cout << "Total # Customers = " << total_customers << "\n";
  std::cout << "Total Wait Time   = " << total_wait_time << "\n";
  std::cout << "Average Wait Time = " << (static_cast<double>(total_wait_time) / total_customers) << "\n";
}
