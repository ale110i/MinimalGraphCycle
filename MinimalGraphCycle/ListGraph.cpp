//
//  ListGraph.cpp
//  GraphRealizationTest
//
//  Created by Alexey Ischenko on 13/02/2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "ListGraph.hpp"

ListGraph::ListGraph(IGraph*& another_graph){
    vertices_count = another_graph->VerticesCount();
    links.resize(vertices_count);
    for (int_fast32_t j = 0; j < another_graph->VerticesCount(); ++j){
        std::vector<int_fast32_t> nv;
        std::vector<int_fast32_t> pv;
        another_graph->GetNextVertices(j, nv);
        another_graph->GetPrevVertices(j, pv);
        for (int_fast32_t i = 0; i < pv.size(); ++i){
            links[j].first.push_back(pv[i]);
        }
        for (int_fast32_t i = 0; i < nv.size(); ++i){
            links[j].second.push_back(nv[i]);
        }
    }
}

ListGraph::ListGraph(int_fast32_t vt_count){
    vertices_count = vt_count;
    links.resize(vertices_count);
}

void ListGraph::AddEdge(int_fast32_t from, int_fast32_t to){
    links[from].second.push_back(to); //Указываем сына
    links[to].first.push_back(from); //Указываем предка
}

int_fast32_t ListGraph::VerticesCount() const {
    return vertices_count;
}

void ListGraph::GetNextVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    for (int_fast32_t j = 0; j < links[vertex].second.size(); ++j){
        vertices.push_back(links[vertex].second.at(j));
    }
}

void ListGraph::GetPrevVertices(int_fast32_t vertex, std::vector<int_fast32_t>& vertices) const {
    for (int_fast32_t j = 0; j < links[vertex].first.size(); ++j){
        vertices.push_back(links[vertex].first.at(j));
    }
}

