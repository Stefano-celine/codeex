#pragma once

#include <utility>
#include <iterator>
#include <algorithm>
#include "Text.hpp"

namespace design_patterns
{
template <typename T>
class CipherDecorator : public Text<T>
{
  public:
    CipherDecorator(const Text<T> &text)
      : text_(text)
    {
        // do nothing
    }
    virtual ~CipherDecorator() = 0;

  protected:
    const Text<T> &text_;
};

template <typename T>
inline CipherDecorator<T>::~CipherDecorator() {}

template <typename T>
class SimpleEncrypt final : public CipherDecorator<T>
{
  public:
    SimpleEncrypt(const Text<T> &text, int step = 5)
      : CipherDecorator<T>(text), step_(step)
    {
        // do nothing
    }

    T getText() const override
    {
        auto literal = this->text_.getText();
        T result = literal;
        for (std::size_t i = 0; i < literal.size(); ++i)
        {
            result[(i + step_) % result.size()] = literal[i];
        }
        return result;
    }

  private:
    const int step_;
};

template <typename T>
class ReverseEncrypt final : public CipherDecorator<T>
{
  public:
    ReverseEncrypt(const Text<T> &text)
      : CipherDecorator<T>(text)
    {
        // do nothing
    }

    T getText() const override
    {
        auto literal = this->text_.getText();
        std::reverse(std::begin(literal), std::end(literal));
        return literal;
    }
};

template <typename T>
class ComplexEncrypt final : public CipherDecorator<T>
{
  public:
    ComplexEncrypt(const Text<T> &text, int leap = 5)
      : CipherDecorator<T>(text), leap_(leap)
    {
        // do nothing
    }

    T getText() const override
    {
        auto literal = this->text_.getText();
        for (auto &each : literal)
        {
            each = each + leap_;
        }
        return literal;
    }

  private:
    const int leap_;
};
} // namespace design_patterns