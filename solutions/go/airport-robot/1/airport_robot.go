// Package airportrobot provides functionalities for greeting
// in different languages.
package airportrobot

import "fmt"

// Greeter is an interface that any language-specific greeter should implement.
// It provides the name of the language and a greeting for a given name.
type Greeter interface {
	// LanguageName returns the name of the language that the greeter implements.
	LanguageName() string

	// Greet returns a greeting in the specific language for the given name.
	Greet(name string) string
}

// SayHello takes a name and a Greeter and returns a greeting message in the format:
// "I can speak [Language]: [Greeting]"
func SayHello(name string, g Greeter) string {
	return fmt.Sprintf("I can speak %s: %s", g.LanguageName(), g.Greet(name))
}

// Italian is a struct that implements the Greeter interface for the Italian language.
type Italian struct{}

// LanguageName returns the name of the Italian language.
func (i Italian) LanguageName() string {
	return "Italian"
}

// Greet returns an Italian greeting for the given name.
func (i Italian) Greet(name string) string {
	return fmt.Sprintf("Ciao %s!", name)
}

// Portuguese is a struct that implements the Greeter interface for the Portuguese language.
type Portuguese struct{}

// LanguageName returns the name of the Portuguese language.
func (p Portuguese) LanguageName() string {
	return "Portuguese"
}

// Greet returns a Portuguese greeting for the given name.
func (p Portuguese) Greet(name string) string {
	return fmt.Sprintf("Olá %s!", name)
}
