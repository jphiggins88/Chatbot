#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot;  // Original Code //TODO: Not needed???

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

/* TODO: am I allowed to modify this???
void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(edge);
}
*/
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
//{
//    //_chatBot = chatbot;   // Original code
//    //_chatBot->SetCurrentNode(this);   // Original code
//    _chatBot = std::move(chatbot);
//    _chatBot.SetCurrentNode(this);
//}

//void GraphNode::MoveChatbotHere(ChatBot& chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //newNode->MoveChatbotHere(_chatBot);   // original code
    //_chatBot = nullptr; // invalidate pointer at source   // original code
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];    // original code
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}