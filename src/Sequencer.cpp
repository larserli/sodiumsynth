#include "Sequencer.h"
#include "Midi.h"

Sequencer::Sequencer(IClockSource* clock): TimeVariant(clock){
	m_at = 0;
}

Sequencer::Sequencer(IClockSource* clock,std::vector<int> sequence) : TimeVariant(clock){
	for(auto &n : sequence){
		m_sequence.push_back(Midi::ToFreq(n));
	}
	m_at = 0;
}

Sequencer::Sequencer(IClockSource* clock, std::vector<std::string> sequence) : TimeVariant(clock){
	for(auto &n : sequence){
		m_sequence.push_back(Midi::ToFreq(n));
	}
	m_at = 0;
}

Sequencer::~Sequencer(){

}

void Sequencer::setSequence(std::vector<int> sequence){
	for(auto &n : sequence){
		m_sequence.push_back(Midi::ToFreq(n));
	}
}

void Sequencer::tick(){
	m_out = m_sequence[m_at++];
	if(m_at > m_sequence.size()){
		m_at = 0;
	}

}
