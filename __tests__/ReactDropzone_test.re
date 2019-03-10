open Jest;
open ExpectJs;


describe("bs-react-dropzone", () => {
  test("react component", () => {
    let component = ReactShallowRenderer.renderWithRenderer(<ReactDropzone>
      ...((_) => ReasonReact.null)
    </ReactDropzone>);

    expect(Js.Undefined.return(component)) |> toBeDefined
  });
});
