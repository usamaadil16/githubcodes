import { StatusBar } from 'expo-status-bar';
//import { StyleSheet, Text, View } from 'react-native';
import React from 'react';
import { View, Text, Image, ScrollView, TextInput } from 'react-native';

const App = () => {
  return (
    <ScrollView style={{marginLeft:10, marginRight:10, marginTop:50}}>
      <Text style={{color:"blue"}}  >Some text</Text>
      <View>
        <Text>Some more text</Text>
        <Image
        
          source={{
            uri: 'https://assets.entrepreneur.com/content/3x2/2000/1639176582-Ent-MrBeats.png?auto=webp&quality=95&crop=16:9&width=675',
          }}
          style={{ marginTop:20, width: 200, height: 200 }}
        />
      </View>
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
      <TextInput
        style={{
          height: 40,
          borderColor: 'gray',
          borderWidth: 1,
          marginTop: 20,
          marginLeft:10,
          marginRight:10

        }}
        defaultValue=" You can type in me"      />
        
    </ScrollView>
  );
}





export default App;
